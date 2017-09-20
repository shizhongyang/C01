#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//动态内存分配
//void main(){
	
	//40M
	//stack overflow  错误 栈溢出
	//静态内存分配
	//int a[1024 * 1024 * 10];
	//栈内存

	//c语言内存分配
	// 1.栈区（stack） ，windows下，桟内存分配2M（确定的常数），超出了限制就会有stack overflow
	//自动分配 释放
	//2.堆区 （heap）
	//程序员手动非配释放，操作系统80%的内存
	//3.全局区和静态区
	//4.字符常量区
	//5.程序代码区



//}


//void statckFun(){
//	int a[1024];
//}

//void heapFun(){
//	//40M内存 
//	//void *  malloc返回任意类型的指针 就是void*
//	int *p = malloc(1024, 1024 * 10 * sizeof(int)); //开辟完了没有释放
//
//
//	//释放 
//	free(p);
//}

////堆内存
//void main(){
//
//	//在堆内存，分配40M
//	while (1){
//		Sleep(1000);
//		heapFun();
//	}
//
//	getchar();
//
//}

//创建一个数组  动态制定数组大小
//(在程序运行的过程中，可以随意开辟指定的大小的内存，以供使用，相当于java的集合）
//静态内存分配 分配内存大小的是固定的问题，
//问题：1.很容易超出桟内存的最大值，
//2.为了防止内存不够用会开辟更多的内存，容易浪费内存
//动态分配内存 在程序运行过程中，动态指定需要使用的内存大小，手动释放，
//释放之后这些内存还可以被重新使用（活水）

//void main(){
//	//静态内存分配创建数组  数组的大小是固定的
//	//int i = 10;
//	//int a[i];
//
//	int len;
//	printf("输入数组的长度");
//	scanf("%d", &len);
//
//	//开辟内存 大小len*4字节
//	int *p = malloc(len*sizeof(int));
//	//p是数组的首地址 也是数组的名称
//	//给数组的元素赋值（使用这一块刚刚开辟出来的内存区域）
//	int i = 0;
//
//	for (; i < len; i++){
//		p[i] =  rand() % 100;
//		printf("%d,%#x\n", p[i], &p[i]);
//	}
//
//	int addlen;
//	printf("输入数组增加的长度");
//	//内存不够用 扩大刚刚分配的内存空间
//	scanf("%d", &addlen);
//
//	//1、原来的内存的指针 2、内存扩大之后的总大小
//	int *p2 = realloc(p, sizeof(int)*(len + addlen));
//	//重新赋值
//	i = 0;
//
//	for (; i < len + addlen; i++){
//		p2[i] = rand() % 100;
//		printf("%d,%#x\n", p2[i], &p2[i]);
//	}
//
//
//	//手动释放内存
//	free(p);
//
//	system("pause");
//
//
//}