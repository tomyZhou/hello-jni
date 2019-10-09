/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.example.hellojni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class HelloJni extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hello_jni);
        TextView tv = (TextView) findViewById(R.id.hello_textview);
        tv.setText(unimplementedStringFromJNI() + add(1, 2));

        Log.e("xx", "调用前num=" + num);
        addNum();
        Log.e("xx", "调用后num=" + addNum());
    }

    static {
        System.loadLibrary("hello-jni");
    }


    public native String stringFromJNI();


    public native String unimplementedStringFromJNI();

    /**
     * 传值相加
     *
     * @param a
     * @param b
     * @return
     */
    public native int add(int a, int b);

    public int num = 10;

    /**
     * 不传参数，直接拿到当前java对象，再取里的属性
     *
     * @return
     */
    public native int addNum();


    public native void log();

    public native void findClassTest();
}
