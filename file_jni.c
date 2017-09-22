#include "com_shixin_jni_JniTest.h"

//JNI（Java Native Interface）
//Java调用C / C++，C / C++调用Java的一套API
//
//1.编写native方法
//2.javah命令，生成.h头文件
//3.复制.h头文件到CPP工程中
//4.复制jni.h和jni_md.h文件到CPP工程中
//5.实现.h头文件中声明的函数
//6.生成dll文件
//7.配置dll文件所在目录到环境变量
//8.重启Eclipse
//
//
//C的函数名称：Java_完整类名_函数名
//
//.a  静态库 
//.dll 共享代码 动态库  windows下面是.dll .dll多个程序共享
//.exe文件中不包含.dll动态库 在外面的文件中，但是包含所有的.a文件
//
//JNIEnv
//
//在C中：
//JNIEnv 结构体指针别名
//env二级指针
//
//在C++中：
//JNIEnv 是一个结构体的别名
//env 一级指针
//
//
//1.为什么需要传入JNIEnv，函数执行过程中需要JNIEnv
//2.C++为什么没有传入？this
//3.C++只是对C的那一套进行的封装，给一个变量赋值为指针，这个变量是二级指针
//
//C / C++中为什么有区别？


//函数实现
JNIEXPORT jstring JNICALL Java_com_shixin_jni_JniTest_getStringFromc
(JNIEnv *env, jclass jcls){
	//JNIEnv 结构体指针  在c++里面就是一个结构体别名
	//env二级指针  在c++是一个一级指针
	//c++仍然用的是c的结构体
	//代表Java运行环境，调用Java中的代码

	//简单的实现
	//将C的字符串转为一个java字符串
	return (*env)->NewStringUTF(env, "C String");
}