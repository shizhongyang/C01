
//�ṹ��ָ�����
typedef struct JNINativeInterface_* JNIEnv;

//�ṹ��
struct JNINativeInterface_{
	char *(*NewStringUTF)(JNIEnv*, char*);
	int *(*NewIntUTF)(JNIEnv, int*);
};

//������ʵ��
char* NewStringUTF(JNIEnv* env, char* str){
	//��NewStringUTFִ�й��̣���Ȼ��ҪJNIEnv
	return str;
}
//������ʵ��
int* NewIntUTF(JNIEnv env, int* i){
	//��NewStringUTFִ�й��̣���Ȼ��ҪJNIEnv
	return i;
}

void change(int m){
	printf("m�ĵ�ַ%x\n", &m);
	m = 5;
	printf("m�ĵ�ַ%x\n", &m);
}

void changeP(int *p //����൱�����¿�����һ���ڴ棬���Ǵ����ֵ  ��java�е�һ��
	){
	printf("p�ĵ�ַ%x\n", &p);
	p = 6;
	printf("p�ĵ�ַ%x\n", p);
}


void main(){
	//ʵ�����ṹ��
	struct JNINativeInterface_ struct_env;
	struct_env.NewStringUTF = NewStringUTF;
	struct_env.NewIntUTF = NewIntUTF;
	//�ṹ��ָ��
	JNIEnv e = &struct_env;

	//�ṹ�����ָ�� 
	JNIEnv *env = &e; 

	//ͨ������ָ����ú���  Ϊʲô�ö���ָ�룿
	//char *str = (*env)->NewStringUTF(env, "acb");

	//printf("%s\n", str);

	//����ָ����� 
	//int *i = (*env)->NewIntUTF(e, 12); 
	//һ��ָ�����
	//int *i = e->NewIntUTF(e, 12);  
	//�ṹ��ʵ�����������
	int *i = struct_env.NewIntUTF(e, 12); 

	printf("%d\n", i);

	int *b = 9;
	/*printf("b�ĵ�ַ%x\n", &b);
	change(b);
	printf("b�ĵ�ַ%x\n", &b);
	printf("%d\n", b);*/

	changeP(b);
	printf("%d\n", b);
	getchar();
}