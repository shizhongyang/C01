#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
//结构体是一种构造数据类型  类似于类
//把不同的数据类型结合起来成为一个自定义数据类型
struct Man{
	char name[20];
	int age;
	//int(*fun_c)();

};

struct Woman{
	char* name;
	int age;
} w1, w2 = {"asdg",23}; //w1 结构体变量名

//匿名的结构体
//控制结构体变量的个数（限量版） 相当于单例
struct 
{
	char name[20];
	int age;
} s1;

//结构体嵌套
struct Tea{
	char name[20];
};

struct Stu
{
	char name[20];
	int age;
	struct Tea t;
};


struct Boos{
	int age;
	struct eme
	{
		char name[20];
	};
};




//void main(){
//	//初始化结构体变量
//	//1.赋值方式  只能在变量名声明时候复制
//	//struct Man m1 = {"jon",21}
//	//m1 = {} 这样赋值不行
//	//2 
//	struct Man m1;
//	m1.age = 23;
//	//m1.name = "s";  这样不能修改
//	strcpy(m1.name, "jack");
//
//	struct Man m2 = m1;
//
//	printf("%s,%d\n", m1.name, m1.age);
//
//
//	struct Woman w;
//	w.age = 23;
//	w.name = "jon";
//
//	printf("%s,%d\n", w.name, w.age);
//
//	getchar();
//}

//结构体的几种写法

//void main(){
//	s1.age = 23;
//	strcpy(s1.name, "jack");
//	printf("%s,%d\n", s1.name, s1.age);
//
//
//	//struct Stu s2 = { "jack", 2, { "sdf" } };
//	struct Stu s2;
//	s2.age = 23;
//	strcpy(s2.t.name, "jack");
//	getchar();
//
//}

/*
//结构体与指针
struct H{
	char name[20];
	int age;
};

typedef struct Ani{
	int age;
};//A,*A1;
typedef struct Ani A;
typedef struct Ani* A1;


void main(){
	struct H h = { "sj", 10 };
	//结构体指针
	struct H *p = &h;



}
*/