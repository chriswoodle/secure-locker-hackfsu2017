const redis = require('redis').createClient({ host: "x.x.x.x" })
const SerialPort = require('serialport');
const exec = require('child_process').exec;

const arduino = new SerialPort('/dev/ttyACM0', {
    baudRate: 115200
});

let locked = null;
let lastLockState = null;
let doorOpen = null;
let touched = false;

let processing = false;

console.log('Starting...');
arduino.on('open', function () {
    // open logic
    console.log('Connected to arduino.');
    unlock();
    arduino.on('data', function (data) {
        //process.stdout.write('Data: ' +  data.toString());
        parseInput(data.toString());
    });
});

let count = 0;

function parseInput(input) {
    if (input.indexOf('#') > -1) {
        const command = input.split('#')[1].trim();
        console.log(command);
        switch (command) {
            case 'touched':
                touched = true;
                console.log(count);
                count++;
                processState();
                break;
            case 'unlocked':
                locked = false;
                processState();
                lastLockState = false;
                break;
            case 'locked':
                locked = true;
                processState();
                lastLockState = true;
                break;
            case 'open':
                doorOpen = true;
                break;
            case 'closed':
                doorOpen = false;
                break;
            default:
                console.log('Unknown command');
        }
    }
}

function unlock() {
    arduino.write('U');
}

function lock() {
    arduino.write('L');
}

function processState() {
    if (processing === true) return;
    //console.log("Processing..");
    if (locked === true && doorOpen === false && touched == true) {
        touched = false;
        processing = true;
        console.log('New challanger has appeared!');
        exec('sudo python captureNrekognize.py', { cwd: '/home/pi/hackfsu' }, (err, stdout, stderr) => {
            processing = false;
            if (err) {
                console.error(err);
                return;
            }
            console.log(stdout);
            if (stdout.indexOf('muntaser') > -1 || stdout.indexOf('woodle') > -1) {
                unlock();
                exec('sudo python lastlockeropentwilio.py', { cwd: '/home/pi/hackfsu' }, (err, stdout, stderr) => {
                    if (err) {
                        console.error(err);
                        return;
                    }
                    console.log(stdout);
                });
            } else {
                exec('sudo python lastlockerattempttwilio.py', { cwd: '/home/pi/hackfsu' }, (err, stdout, stderr) => {
                    if (err) {
                        console.error(err);
                        return;
                    }
                    console.log(stdout);
                });
            }
        });
    }
    touched = false;


}

redis.on("message", function (channel, message) {
    console.log("sub channel " + channel + ": " + message);
    if (message == 'pass') unlock();
});

redis.subscribe("override");

