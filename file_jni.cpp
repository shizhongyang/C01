#include "com_shixin_jni_JniTest.h"

//����ʵ��
JNIEXPORT jstring JNICALL Java_com_shixin_jni_JniTest_getStringFromc
(JNIEnv *env, jclass jcls){
	//JNIEnv ��C++�о���һ���ṹ��ı���
	//env ��C++��һ���ṹ���һ��ָ��
	return env->NewStringUTF("C String");
}