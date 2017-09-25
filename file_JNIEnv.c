
//结构体指针别名
typedef struct JNINativeInterface_* JNIEnv;

//结构体
struct JNINativeInterface_{
	char *(*NewStringUTF)(JNIEnv*, char*);
	int *(*NewIntUTF)(JNIEnv, int*);
};

//函数的实现
char* NewStringUTF(JNIEnv* env, char* str){
	//在NewStringUTF执行过程，仍然需要JNIEnv
	return str;
}
//函数的实现
int* NewIntUTF(JNIEnv env, int* i){
	//在NewStringUTF执行过程，仍然需要JNIEnv
	return i;
}

void change(int m){
	printf("m的地址%x\n", &m);
	m = 5;
	printf("m的地址%x\n", &m);
}

void changeP(int *p //这个相当于重新开辟了一块内存，不是传入的值  和java中的一样
	){
	printf("p的地址%x\n", &p);
	p = 6;
	printf("p的地址%x\n", p);
}


void main(){
	//实例化结构体
	struct JNINativeInterface_ struct_env;
	struct_env.NewStringUTF = NewStringUTF;
	struct_env.NewIntUTF = NewIntUTF;
	//结构体指针
	JNIEnv e = &struct_env;

	//结构体二级指针 
	JNIEnv *env = &e; 

	//通过二级指针调用函数  为什么用二级指针？
	//char *str = (*env)->NewStringUTF(env, "acb");

	//printf("%s\n", str);

	//二级指针调用 
	//int *i = (*env)->NewIntUTF(e, 12); 
	//一级指针调用
	//int *i = e->NewIntUTF(e, 12);  
	//结构体实例化本身调用
	int *i = struct_env.NewIntUTF(e, 12); 

	printf("%d\n", i);

	int *b = 9;
	/*printf("b的地址%x\n", &b);
	change(b);
	printf("b的地址%x\n", &b);
	printf("%d\n", b);*/

	changeP(b);
	printf("%d\n", b);
	getchar();
}