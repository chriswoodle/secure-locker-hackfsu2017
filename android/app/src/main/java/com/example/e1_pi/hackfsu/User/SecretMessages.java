package com.example.e1_pi.hackfsu.User;

import android.app.Activity;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


import com.example.e1_pi.hackfsu.R;


import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;


public class SecretMessages extends AppCompatActivity {
    EditText code;
    Button override_btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_secret_messages);

        code = (EditText) findViewById(R.id.control_code);
        override_btn = (Button) findViewById(R.id.override_btn);

        override_btn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                // Create a new HttpClient and Post Header


                Thread thread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            HttpClient httpclient = new DefaultHttpClient();
                            HttpPost httppost = new HttpPost("http://192.168.1.78:8089");
                            // Add your data
                            List<NameValuePair> nameValuePairs = new ArrayList<NameValuePair>(2);
                            nameValuePairs.add(new BasicNameValuePair("id", "12345"));
                            nameValuePairs.add(new BasicNameValuePair("stringdata", "AndDev is Cool!"));
                            httppost.setEntity(new UrlEncodedFormEntity(nameValuePairs));

                            // Execute HTTP Post Request
                            HttpResponse response = httpclient.execute(httppost);

                            Toast.makeText(getApplicationContext(), "Ok", Toast.LENGTH_LONG).show();

                        } catch (ClientProtocolException e) {
                            // TODO Auto-generated catch block
                            Toast.makeText(getApplicationContext(), e.toString(), Toast.LENGTH_LONG).show();
                        } catch (IOException e) {
                            // TODO Auto-generated catch block
                            Toast.makeText(getApplicationContext(), e.toString(), Toast.LENGTH_LONG).show();
                        }


                    }
                });
                thread.start();



            }
        });

    }

}
