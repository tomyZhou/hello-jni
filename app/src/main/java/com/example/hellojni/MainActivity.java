package com.example.hellojni;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private TextView hello_textview;

    @Override
    protected void
    onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        hello_textview = findViewById(R.id.hello_textview);
        hello_textview.setText(new JNIUtil().sayHello() + new JNIUtil().sum(1, 2));

        Log.d("XX", new JNIUtil().sayHello());
        Toast.makeText(this, new JNIUtil().sayHello(), Toast.LENGTH_SHORT).show();

        if (new JNIUtil().checkPwd("123456") == 0) {
            Toast.makeText(this, "密码正确", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "密码错误", Toast.LENGTH_SHORT).show();
        }

        Resources res = getResources();
        Bitmap bmp = BitmapFactory.decodeResource(res, R.drawable.timg);
        new JNIUtil().getBitmapInfo(bmp);

        int[] array = {1, 8, 3, 9, 22, 5, 10, 73, 4};
        new JNIUtil().arraySort(array);

        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }


    }
}
