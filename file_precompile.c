#include <stdlib.h>
#include <stdio.h>


//C语言执行的流程
//编译：形成目标代码(.obj)
//连接：将目标代码与C函数库连接合并，形成最终的可执行文件  错误阶段是link阶段
//执行

//预编译（预处理），为编译做准备工作，完成代码文本的替换工作
//C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include
//C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\crt\src

//头文件告诉编译器有这样一个函数，连接器负责找到这个函数的实现

//宏定义、宏替换、预编译指令
//define指令
//1.定义标示
//#ifdef __cplusplus 标识支持C++语法 //防止文件重复引入
//#ifdef ANDROID 在android下面编译

//2.定义常数（便于修改与阅读）
#define MAX 100  //没有类型 宏定义
//int MIN = 40;
//3.定义“宏函数”
void dn_com_jni_read(){
	printf("read\n");
}

void dn_com_jni_write(){
	printf("wtrite\n");
}

//NAME是参数  宏函数 方便调用
#define jni(NAME) dn_com_jni_##NAME();
//webrtc JNI函数名称很长，也是JOW宏函数缩短函数名称

//日志输出
//__VA_ARGS__可变参数
//#define LOG(FORMAT,...) printf(##FORMAT,__VA_ARGS__); 
////日志会有级别
//#define LOG_I(FORMAT,...) printf("INFO:"); printf(##FORMAT,__VA_ARGS__); 
//#define LOG_E(FORMAT,...) printf("ERRO:"); printf(##FORMAT,__VA_ARGS__); 

//升级版本  leve format 参数 替换内容
#define LOG(LEVEL,FORMAT,...) printf(##LEVEL); printf(##FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT,...) LOG("ERROR:",##FORMAT,__VA_ARGS__);
#define LOG_W(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__);

//Android
//#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);
//LOGI("%s","fix");
//替换
//__android_log_print(ANDROID_LOG_INFO, "jason", "%s", "fix");

void main(){

	//#include "my.txt";
	//jni(read)
	jni(write);//替换：dn_com_jni_write();

	LOG_E("%s%d", "大小：", 89);
	//替换成：printf("INFO:"); printf("%s%d","大小：",89);
	//LOG_I

	getchar();
}











