package com.example.hellojni;

import android.graphics.Bitmap;

public class JNIUtil {

    {
        System.loadLibrary("fileUtil");
    }

    //定义native方法
    //调用C代码对应的方法
    public native String sayHello();

    public native int sum (int x ,int y);

    public native int checkPwd(String pwd);

    public native void getBitmapInfo(Bitmap bitmap);

}
