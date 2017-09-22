#include "com_shixin_jni_JniTest.h"

//函数实现
JNIEXPORT jstring JNICALL Java_com_shixin_jni_JniTest_getStringFromc
(JNIEnv *env, jclass jcls){
	//JNIEnv 在C++中就是一个结构体的别名
	//env 在C++中一个结构体的一级指针
	return env->NewStringUTF("C String");
}