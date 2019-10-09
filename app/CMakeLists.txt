#CMake 的编译脚本配置文件

# 1.标注CMake需要支持的CMake最小版本
cmake_minimum_required(VERSION 3.4.1)

file(GLOB native_srcs "src/main/jni/*.cpp")

# 2.add_library 定义需要编译的代码库 名称、类型、包含的源码
add_library(
    #sets the name of the library
    fileUtil
    #sets the library as shared library
    SHARED
    #set the source file
    # src/main/jni/testOne.cpp  #添加一个源文件
    ${native_srcs}              #添加多个源文件
)

# 3.find_library 定义当前代码库需要依赖的系统或者三方库文件(可以写多个)
find_library(
    log_lib #指定要查找的系统库，给一个名字
    log     #真正要查找的liblog.so 或者 liblog.a
)

# 4.target_link_libraries 设置最终编译的目标代码库
target_link_libraries(
     fileUtil    #add_library 生成的
      # 加上下面这一行 #要使用 的话，必须要链接 jnigraphics 库，否则会报类似 undefined reference to ‘AndroidBitmap_getInfo’ 这样的错误
     jnigraphics
     ${log_lib}  #find_library 找到的系统库
)


