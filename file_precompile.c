#include <stdlib.h>
#include <stdio.h>


//C����ִ�е�����
//���룺�γ�Ŀ�����(.obj)
//���ӣ���Ŀ�������C���������Ӻϲ����γ����յĿ�ִ���ļ�  ����׶���link�׶�
//ִ��

//Ԥ���루Ԥ������Ϊ������׼����������ɴ����ı����滻����
//C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include
//C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\crt\src

//ͷ�ļ����߱�����������һ�������������������ҵ����������ʵ��

//�궨�塢���滻��Ԥ����ָ��
//defineָ��
//1.�����ʾ
//#ifdef __cplusplus ��ʶ֧��C++�﷨ //��ֹ�ļ��ظ�����
//#ifdef ANDROID ��android�������

//2.���峣���������޸����Ķ���
#define MAX 100  //û������ �궨��
//int MIN = 40;
//3.���塰�꺯����
void dn_com_jni_read(){
	printf("read\n");
}

void dn_com_jni_write(){
	printf("wtrite\n");
}

//NAME�ǲ���  �꺯�� �������
#define jni(NAME) dn_com_jni_##NAME();
//webrtc JNI�������ƺܳ���Ҳ��JOW�꺯�����̺�������

//��־���
//__VA_ARGS__�ɱ����
//#define LOG(FORMAT,...) printf(##FORMAT,__VA_ARGS__); 
////��־���м���
//#define LOG_I(FORMAT,...) printf("INFO:"); printf(##FORMAT,__VA_ARGS__); 
//#define LOG_E(FORMAT,...) printf("ERRO:"); printf(##FORMAT,__VA_ARGS__); 

//�����汾  leve format ���� �滻����
#define LOG(LEVEL,FORMAT,...) printf(##LEVEL); printf(##FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT,...) LOG("ERROR:",##FORMAT,__VA_ARGS__);
#define LOG_W(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__);

//Android
//#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);
//LOGI("%s","fix");
//�滻
//__android_log_print(ANDROID_LOG_INFO, "jason", "%s", "fix");

void main(){

	//#include "my.txt";
	//jni(read)
	jni(write);//�滻��dn_com_jni_write();

	LOG_E("%s%d", "��С��", 89);
	//�滻�ɣ�printf("INFO:"); printf("%s%d","��С��",89);
	//LOG_I

	getchar();
}











