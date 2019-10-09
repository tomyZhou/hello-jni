//
// Created by zhougang on 2019/10/9.
//

#include <jni.h>
#include "LogUtil.h"
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <android/bitmap.h>
#include "com_example_hellojni_JNIUtil.h"

/*
 * Class:     com_example_hellojni_JNIUtil
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT jstring JNICALL Java_com_example_hellojni_JNIUtil_sayHello(JNIEnv *env, jobject instance){
    return env->NewStringUTF("没想到吧！我竟然会JNI了！！！");
  }

 JNIEXPORT jint JNICALL Java_com_example_hellojni_JNIUtil_sum(JNIEnv *env,jobject instance,jint x,jint y){
    int result = x+y;
    return result;
 }

 char *jstringToChar(JNIEnv *env, jstring jstr) {
     char *rtn = NULL;
     jclass clsstring = env->FindClass("java/lang/String");
     jstring strencode = env->NewStringUTF("GB2312");
     jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
     jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
     jsize alen = env->GetArrayLength(barr);
     jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
     if (alen > 0) {
         rtn = (char *) malloc(alen + 1);
         memcpy(rtn, ba, alen);
         rtn[alen] = 0;
     }
     env->ReleaseByteArrayElements(barr, ba, 0);
     return rtn;
 }


 JNIEXPORT int JNICALL Java_com_example_hellojni_JNIUtil_checkPwd(JNIEnv *env,jobject instance,jstring pwd_){
    char *originPwd = "123456";
    char *formPwd = jstringToChar(env,pwd_);
    int code = strcmp(originPwd,formPwd);
    return code;
 }

JNIEXPORT void JNICALL Java_com_example_hellojni_JNIUtil_getBitmapInfo(JNIEnv *env,jobject instance,jobject bitmap){
    if(NULL == bitmap){
        LOGE("bitmap is null");
        return;
    }

    AndroidBitmapInfo info;
    int result;

    //获取图片信息
    result = AndroidBitmap_getInfo(env,bitmap,&info);
    if(result != ANDROID_BITMAP_RESULT_SUCCESS){
        LOGE("AndroidBitmap_getInfo failed ,result:%d",result);
        return;
    }

    LOGD("bitmap width: %d,height: %d,format: %d,stride: %d",info.width,info.height,info.format,info.stride);

}
