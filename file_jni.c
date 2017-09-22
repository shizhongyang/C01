#include "com_shixin_jni_JniTest.h"

//JNI��Java Native Interface��
//Java����C / C++��C / C++����Java��һ��API
//
//1.��дnative����
//2.javah�������.hͷ�ļ�
//3.����.hͷ�ļ���CPP������
//4.����jni.h��jni_md.h�ļ���CPP������
//5.ʵ��.hͷ�ļ��������ĺ���
//6.����dll�ļ�
//7.����dll�ļ�����Ŀ¼����������
//8.����Eclipse
//
//
//C�ĺ������ƣ�Java_��������_������
//
//.a  ��̬�� 
//.dll ������� ��̬��  windows������.dll .dll���������
//.exe�ļ��в�����.dll��̬�� ��������ļ��У����ǰ������е�.a�ļ�
//
//JNIEnv
//
//��C�У�
//JNIEnv �ṹ��ָ�����
//env����ָ��
//
//��C++�У�
//JNIEnv ��һ���ṹ��ı���
//env һ��ָ��
//
//
//1.Ϊʲô��Ҫ����JNIEnv������ִ�й�������ҪJNIEnv
//2.C++Ϊʲôû�д��룿this
//3.C++ֻ�Ƕ�C����һ�׽��еķ�װ����һ��������ֵΪָ�룬��������Ƕ���ָ��
//
//C / C++��Ϊʲô������


//����ʵ��
JNIEXPORT jstring JNICALL Java_com_shixin_jni_JniTest_getStringFromc
(JNIEnv *env, jclass jcls){
	//JNIEnv �ṹ��ָ��  ��c++�������һ���ṹ�����
	//env����ָ��  ��c++��һ��һ��ָ��
	//c++��Ȼ�õ���c�Ľṹ��
	//����Java���л���������Java�еĴ���

	//�򵥵�ʵ��
	//��C���ַ���תΪһ��java�ַ���
	return (*env)->NewStringUTF(env, "C String");
}