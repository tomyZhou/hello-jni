//
// Created by zhougang on 2019/10/12.
//

#include "testTwo.h"

#include <stdio.h>

//--------宏函数示例：
//--------参数NAME,使用时格式为##NAME。既可以用来替换函数名，也可以用来替换函数里的参数。
//--------下面代码中LEVE,FORMAT都是自定义的 ， 可以是任意名称 ， 只有后面替换的名称一致即可。
//---------LOG(LEVE,FORMAT,...)中的...表示可变参数 ， 替换则是使用__VA_ARGS__这种固定写法 。

void _jni_define_read(){
	printf("我是read函数\n");
}

void _jni_define_write(){
	printf("我是write函数\n");
}

#define jni(NAME) _jni_define_##NAME();

#define LOG(LEVEL,FORMAT,...) printf("##LEVEL);printf(##FORMAT,_VA_ARGS_);
#define LOGI(FORMAT,...) LOG("INFO",##FORMAT,_VA_ARGS_);
#define LOGW(FORMAT,...) LOG("WARN",##FROMAT,_VA_ARGS_);
#define	LOGE(FORMAT,...) LOG("ERROR",##FORMAT,_VA_ARGS);

void main(){
  jni(read);

  jni(write);

  LOGI("%s","自定义日志...\n");

  LOGE("%s","我是错误日志\n");

}
