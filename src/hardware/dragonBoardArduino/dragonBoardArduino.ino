
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

#include <SPI.h>
#include <MFRC522.h>


/*
 *  * Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS      SDA(SS)      10            53        D10        10               10
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {

  Serial.begin(115200);    // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  pixels.begin(); // This initializes the NeoPixel library.
  blink(0, 0, 40, 5, 100);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  //Serial.println(mfrc522.uid.uidByte[0]);
  //Serial.println(mfrc522.uid.uidByte[1]);
  //Serial.println(mfrc522.uid.uidByte[2]);
  //Serial.println(mfrc522.uid.uidByte[3]);
  if (
    mfrc522.uid.uidByte[0] == 176 &&
    mfrc522.uid.uidByte[1] == 168 &&
    mfrc522.uid.uidByte[2] == 200 &&
    mfrc522.uid.uidByte[3] == 87) {
    Serial.println("pass");
    blink(0, 40, 0, 3, 200);
  } else {
    Serial.println("fail");
    blink(40, 0, 0, 3, 200);
  }
  
  
  delay(2000);

}

void blink(int r, int g, int b, int count, int delayval) {
  for (int blinks = 0; blinks < count; blinks++) {
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b, 2)); // green color.
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval);
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0)); // Clear color.
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval);
  }
}