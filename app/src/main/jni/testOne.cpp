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

/**
 *       1.ANSI标准五个预定义的宏名
 *       __LINE__ 表示该行代码的所在行号
 *      __FILE__ 表示源文件的文件名
 *      __DATE__ 表示源文件被编译的日期，格式(月/日/年)
 *      __TIME__ 表示源文件被编译成目标代码的时间，格式(时:分:秒)
 *      __STDC__ 表示编译器是否标准，标准时表示常量1，非标准则表示其它数字
 */



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
    char* originPwd = "123456";
    char* formPwd = jstringToChar(env,pwd_);
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

// sort
int compare(const void * a,const void * b) {
   return *(int *)a - *(int *)b;
}


//对java传过来的数组排序
JNIEXPORT void JNICALL
Java_com_example_hellojni_JNIUtil_arraySort(JNIEnv *env,jobject instance,jintArray jarray){
    jint* arrayElements = env->GetIntArrayElements(jarray,NULL);
    jsize arraySize = env->GetArrayLength(jarray);
    qsort(arrayElements,arraySize,sizeof(jint),compare);

   // 释放引用 ， 因为数组和对象在java中都是引用 ， 都会在堆内存中开辟一块空间 ， 但我们使用完对象之后
    // 需要将引用释放掉 ， 不然会很耗内存 ， 在一定程度上可能会造成内存溢出 。
    //JNI_ABORT, Java数组不进行更新，但是释放C/C++数组
    //JNI_COMMIT，Java数组进行更新，不释放C/C++数组（函数执行完，数组还是会释放）
    env->ReleaseIntArrayElements(jarray,arrayElements,JNI_COMMIT);
}
