#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
//�ṹ����һ�ֹ�����������  ��������
//�Ѳ�ͬ���������ͽ��������Ϊһ���Զ�����������
struct Man{
	char name[20];
	int age;
	//int(*fun_c)();

};

struct Woman{
	char* name;
	int age;
} w1, w2 = {"asdg",23}; //w1 �ṹ�������

//�����Ľṹ��
//���ƽṹ������ĸ����������棩 �൱�ڵ���
struct 
{
	char name[20];
	int age;
} s1;

//�ṹ��Ƕ��
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
//	//��ʼ���ṹ�����
//	//1.��ֵ��ʽ  ֻ���ڱ���������ʱ����
//	//struct Man m1 = {"jon",21}
//	//m1 = {} ������ֵ����
//	//2 
//	struct Man m1;
//	m1.age = 23;
//	//m1.name = "s";  ���������޸�
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

//�ṹ��ļ���д��

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
//�ṹ����ָ��
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
	//�ṹ��ָ��
	struct H *p = &h;



}
*/