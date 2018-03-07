package com.example.e1_pi.hackfsu;

import android.util.Log;
import android.widget.Toast;

import com.google.firebase.iid.FirebaseInstanceId;
import com.google.firebase.iid.FirebaseInstanceIdService;
import com.google.firebase.messaging.FirebaseMessaging;

/**
 * Created by e1_pi on 03-Mar-18.
 */

public class MyFirebaseInstanceIdService extends FirebaseInstanceIdService {
    private static final String REGISTER_TOKEN = "REG_TOKEN";

    @Override
    public void onTokenRefresh() {
        String recentToken = FirebaseInstanceId.getInstance().getToken();
        FirebaseMessaging.getInstance().subscribeToTopic("GLOBALgroup");
        Log.d(REGISTER_TOKEN, recentToken);

    }
}
