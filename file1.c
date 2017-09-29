#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int x = 20; //ȫ�ֱ���������

/* �ַ����Ĳ���
	1	strcpy(s1, s2);
	�����ַ��� s2 ���ַ��� s1��
	2	strcat(s1, s2);
	�����ַ��� s2 ���ַ��� s1 ��ĩβ��
	3	strlen(s1);
	�����ַ��� s1 �ĳ��ȡ�
	4	strcmp(s1, s2);
	��� s1 �� s2 ����ͬ�ģ��򷵻� 0����� s1<s2 �򷵻�С�� 0����� s1>s2 �򷵻ش��� 0��
	5	strchr(s1, ch);
	����һ��ָ�룬ָ���ַ��� s1 ���ַ� ch �ĵ�һ�γ��ֵ�λ�á�
	6	strstr(s1, s2);
	����һ��ָ�룬ָ���ַ��� s1 ���ַ��� s2 �ĵ�һ�γ��ֵ�λ��
*/


void Pros(char* a, int b, int e, char et); // �βΣ�ֻ����
void test();  
void testStu();
void testFile(); //д�ļ�  ��������
void readFile(); // ���ļ�
void testSeek(); //����fseek����

void testHong();//���Ժ�
double  average(int num, ...); //�ɱ����
void testZhizhen(); //����ָ��

int max(int x, int y);
//typedef int(*fun_ptr)(int, int); // ����һ��ָ��ͬ������������ֵ�ĺ���ָ������
int testPoniterfun(int (*fun_ptr)(int,int),int m,int n); //�������������Ժ����Ļص�
//int testPoniterfun(int(*fun_ptr)(int x, int y), int m, int n); //���������ĺ�����һ����


int getNextRandomValue(void);
void populate_array(int *array, size_t arraySize, int(*getNextValue)(void));

//  ����ṹ
/*  Ϊ�˶���ṹ��������ʹ�� struct ��䡣struct ��䶨����һ�����������Ա���µ��������ͣ�struct ���ĸ�ʽ���£�
	struct [structure tag]
	{
	member definition;
	member definition;
	...
	member definition;
	} [one or more structure variables];

	structure tag �ǿ�ѡ�ģ�ÿ�� member definition �Ǳ�׼�ı������壬
	���� int i; ���� float f; ����������Ч�ı������塣�ڽṹ�����ĩβ�����һ���ֺ�֮ǰ��
	������ָ��һ�������ṹ���������ǿ�ѡ�ġ����������� Book �ṹ�ķ�ʽ��

	Ϊ�˷��ʽṹ�ĳ�Ա������ʹ�ó�Ա�����������.������Ա����������ǽṹ�������ƺ�����Ҫ���ʵ�
	�ṹ��Ա֮���һ����š�������ʹ�� struct �ؼ���������ṹ���͵ı����������ʵ����ʾ�˽ṹ���÷���
*/
struct Books{
	char title[50];
	char author[50];
	char sbject[50];
	int book_id;

};

typedef struct Stus{
	char name[50];
	char gender[20];
} Stu ;

/*  �ṹ��Ϊ�������� 
	�����԰ѽṹ��Ϊ�������������η�ʽ���������͵ı�����ָ�����ơ�������ʹ������ʵ���еķ�ʽ�����ʽṹ������
*/
//void printBook(struct Books book);


/*  ָ��ṹ��ָ��
	�����Զ���ָ��ṹ��ָ�룬��ʽ�붨��ָ���������ͱ�����ָ�����ƣ�������ʾ��
	struct Books *struct_pointer;
	���ڣ������������������ָ������д洢�ṹ�����ĵ�ַ��Ϊ�˲��ҽṹ�����ĵ�ַ����� & ��������ڽṹ���Ƶ�ǰ�棬������ʾ��
	struct_pointer = &Book1;
	Ϊ��ʹ��ָ��ýṹ��ָ����ʽṹ�ĳ�Ա��������ʹ�� -> �������������ʾ��
	struct_pointer->title;
*/
void printBook(struct Books *book);

//λ��
/*  
	��Щ��Ϣ�ڴ洢ʱ��������Ҫռ��һ���������ֽڣ���ֻ��ռ������һ��������λ�������ڴ��һ��������ʱ��ֻ�� 0 �� 1 ����״̬���� 1 λ����λ���ɡ�Ϊ�˽�ʡ�洢�ռ䣬��ʹ�����㣬C �������ṩ��һ�����ݽṹ����Ϊ"λ��"��"λ��"��
	��ν"λ��"�ǰ�һ���ֽ��еĶ���λ����Ϊ������ͬ�����򣬲�˵��ÿ�������λ����ÿ������һ�������������ڳ����а��������в����������Ϳ��԰Ѽ�����ͬ�Ķ�����һ���ֽڵĶ�����λ������ʾ��
	���͵�ʵ����
	�� 1 λ����λ���һ��������ʱ��ֻ�� 0 �� 1 ����״̬��
	��ȡ�ⲿ�ļ���ʽ�������Զ�ȡ�Ǳ�׼���ļ���ʽ�����磺9 λ��������

	λ��Ķ����λ�������˵��
	λ������ṹ������£�����ʽΪ��
	struct λ��ṹ��
	{

	λ���б�

	};

	����λ���б����ʽΪ��
	����˵���� λ����: λ�򳤶�

	���磺
	struct bs{
		int a:8;
		int b:2;
		int c:6;
	}data;  ˵�� data Ϊ bs ��������ռ�����ֽڡ�����λ�� a ռ 8 λ��λ�� b ռ 2 λ��λ�� c ռ 6 λ��


	������������һ��ʵ����
	struct packed_struct {
		unsigned int f1:1;
		unsigned int f2:1;
		unsigned int f3:1;
		unsigned int f4:1;
		unsigned int type:4;
		unsigned int my_int:9;
	} pack; //�����packed_struct ������ 6 ����Ա���ĸ� 1 λ�ı�ʶ�� f1..f4��һ�� 4 λ�� type ��һ�� 9 λ�� my_int��

	����λ��Ķ����������¼���˵����
	һ��λ�����洢��ͬһ���ֽ��У����ܿ������ֽڡ���һ���ֽ���ʣ�ռ䲻�������һλ��ʱ��Ӧ����һ��Ԫ���Ÿ�λ��Ҳ��������ʹĳλ�����һ��Ԫ��ʼ�����磺
	struct bs{
		unsigned a:4;
		unsigned  :4;     ���� 
		unsigned b : 4;    ����һ��Ԫ��ʼ��� 
		unsigned c : 4
	}
	�����λ�����У�a ռ��һ�ֽڵ� 4 λ���� 4 λ�� 0 ��ʾ��ʹ�ã�b �ӵڶ��ֽڿ�ʼ��ռ�� 4 λ��c ռ�� 4 λ��
	����λ������������ֽڣ����λ��ĳ��Ȳ��ܴ���һ���ֽڵĳ��ȣ�Ҳ����˵���ܳ���8λ����λ�������󳤶ȴ��ڼ�����������ֳ���һЩ���������ܻ���������ڴ��ص�������һЩ���������ܻ�Ѵ���һ����Ĳ��ִ洢����һ�����С�
	λ�����������λ����ʱ��ֻ�������������λ�á�������λ���ǲ���ʹ�õġ����磺
	struct k{
		int a : 1;
		int : 2;     �� 2 λ����ʹ�� 
		int b : 3;
		int c : 2;
	};
	�����Ϸ������Կ�����λ���ڱ����Ͼ���һ�ֽṹ���ͣ��������Ա�ǰ�����λ����ġ�

	λ���ʹ��
	λ���ʹ�úͽṹ��Ա��ʹ����ͬ����һ����ʽΪ��

		λ�������.λ����
		λ�������->λ����

	λ�������ø��ָ�ʽ�����

*/
struct bs{
	unsigned a : 1;
	unsigned b : 3;
	unsigned c : 4;
} bit, *pbit;

typedef struct
{
	unsigned char a;
	unsigned int  b;
	unsigned char c;
} debug_size1_t;

typedef struct
{
	unsigned char a;
	unsigned char b;
	unsigned int  c;

} debug_size2_t;



// �ַ����������������#��  �������������\��
#define  message_for(a, b)  \
	printf(#a " and " #b ": We love you!\n")

//�ݹ�
double factorial(unsigned int i)
{
	if (i <= 1){
		return 1;
	}
	return i * factorial(i - 1);
}


//void main()
//{
//	int  var1;
//	char var2[10];
//
//	printf("var1 �����ĵ�ַ�� %p\n", &var1);
//	printf("var2 �����ĵ�ַ�� %p\n", &var2);
//
//	/* ���������еľֲ��������� */
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//
//
//	//int var = 20;
//	//int *ip; //ָ���������
//	//ip = &var;
//	//printf("address of var varable :%x\n", &var);
//	///* ��ָ������д洢�ĵ�ַ */
//	//printf("Address stored in ip variable: %x\n", ip);
//	//*ip = 30;  //ָ��30
//	///* ʹ��ָ�����ֵ */
//	//printf("Value of *ip variable: %d\n", *ip);
//
//	//Pros("Hello", 5, 66666, 'a'); // ʵ�Σ��Ѹ�ֵ
//
//	//char str1[12] = "Hello";
//	//char str2[12] = "World";
//	//char str3[12];
//	///* ���� str1 �� str3 */
//	//strcpy(str3, str1);
//	//printf("strcpy( str3, str1) :  %s\n", str3);
//
//	//test();
//	//testStu();
//	//int c;
//	//printf("enter a value:");
//	//c = getchar();
//	//printf("\n You entered:");
//	//putchar(c);
//	//printf("\n");
//
//	//testFile();
//
//	//readFile();
//
//	//testSeek();
//
//	//testHong();
//
//	//message_for(Carole, Debra);
//
//	//	int i = 16;
//
//	//	printf("%d �Ľ׳�Ϊ %d\n", i, factorial(i));
//
//	//printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
//
//	//testZhizhen();
//
//	/*int s = testPoniterfun(max,3, 4);
//	printf("s��ֵΪ %d\n", s);*/
//
//	/*int myarray[10];
//	populate_array(myarray, 10, getNextRandomValue);
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", myarray[i]);
//	}
//	printf("\n");*/
//
//	//bit.a = 1;    /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
//	//bit.b = 7;    /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
//	//bit.c = 15;    /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
//	//printf("%d,%d,%d\n", bit.a, bit.b, bit.c);    /* ����������ʽ�������������� */
//
//	printf("debug_size1_t size=%lu,debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
//
//	system("pause");
//
//	//return 0;
//
//}


/*����ƫ��ֵ���ʺ����β�����ʵ��*/
//����ָ��
void Pros(char* a, int b, int e, char et)
{
	char **p = &a;
	//a==*p
	printf("%p %p %p %p \n%p\n", &a, p, a, *p, &b);
	printf("%s\n", *p);
	p++;
	printf("%d\n", *p);
	p++;
	printf("%d\n", *p);
	p++;
	printf("%c\n", *p);
}



void test(){

	struct Books book1;

	strcpy(book1.title, "C Programming");
	strcpy(book1.author, "Huha Ali");
	strcpy(book1.sbject, "C Programming Tutorial");
	book1.book_id = 6495407;

	//printBook(book1);
	printBook( &book1 );
	/* ��� Book1 ��Ϣ */
	printf("Book 1 title : %s\n", book1.title);

}

//void printBook(struct Books book)
//{
//	printf("Book title : %s\n", book.title);
//	printf("Book author : %s\n", book.author);
//	printf("Book subject : %s\n", book.sbject);
//	printf("Book book_id : %d\n", book.book_id);
//}

//Ϊ��ʹ��ָ��ýṹ��ָ����ʽṹ�ĳ�Ա��������ʹ�� -> �������������ʾ��
void printBook(struct Books *book)
{
	printf("Book- title : %s\n", book->title);
	printf("Book- author : %s\n", book->author);
	printf("Book- subject : %s\n", book->sbject);
	printf("Book- book_id : %d\n", book->book_id);
}


//����typedef
void testStu(){
	Stu stu;
	strcpy(stu.gender, "��");
	strcpy(stu.name, "hello");
	printf("���� : %s\n", stu.name);
}

//�ļ��Ķ�д
void testFile(){
	FILE *fp = NULL;

	//FILE *fopen( const char * filename, const char * mode ); ���ļ� 
	// mode "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
	fp = fopen("D:/elinkdeyuan/test.txt","w+");
	//int fputc( int c, FILE *fp );
	fprintf(fp, "This is testing for fprintf...\n");
	//int fputs( const char *s, FILE *fp );
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
}


void readFile(){
	FILE *fp = NULL;
	char buff[255];

	fp = fopen("D:/elinkdeyuan/test.txt", "r");
	fscanf(fp, "%s", buff);
	printf("1 : %s\n", buff);

	fgets(buff, 255, (FILE*)fp);
	printf("2: %s\n", buff);

	fgets(buff, 255, (FILE*)fp);
	printf("3: %s\n", buff);
	fclose(fp);


	//1 : This
	//2: is testing for fprintf...

	//	3 : This is testing for fputs...

	//���ȣ�fscanf() ����ֻ��ȡ�� This����Ϊ���ں��������һ���ո�
	//��Σ����� fgets() ��ȡʣ��Ĳ��֣�ֱ����β����󣬵��� fgets() �����ض�ȡ�ڶ��С�
}


void testSeek(){
	FILE *fp = NULL;
	fp = fopen("D:/elinkdeyuan/test.txt", "r+");  // ȷ�� test.txt �ļ��Ѵ���
	fprintf(fp, "This is testing for fprintf...\n");
	fseek(fp, 10, SEEK_SET);
	if (fputc(65, fp) == EOF) {
		printf("fputc fail");
	}
	fclose(fp);
}




void testHong(){
	printf("File :%s\n", __FILE__);
	printf("Date :%s\n", __DATE__);
	printf("Time :%s\n", __TIME__);
	printf("Line :%d\n", __LINE__);
	//printf("ANSI :%d\n", __STDC__);
}



double average(int num, ...)
{

	va_list valist;
	double sum = 0.0;
	int i;

	/* Ϊ num ��������ʼ�� valist */
	va_start(valist, num);

	/* �������и��� valist �Ĳ��� */
	for (i = 0; i < num; i++)
	{
		sum += va_arg(valist, int);
	}
	/* ����Ϊ valist �������ڴ� */
	va_end(valist);

	return sum / num;
}


void testZhizhen(){
//	char a[20];
	char a[20] = "You_are_a_girl";

	//char *ptr = a;  
	//char *ptr = &a;
	char *ptr = &a[0];  //��������д���ǽ����һ�µĶ��ǵõ�������׵�ַ
	//int *ptr = (int *)a; //ǿ������ת��������ı�a ������  
	printf("ptrָ��  :%d\n", ptr); 
	printf("ptrָ��2  :%c\n", *ptr);
	printf("ptrָ��&  :%d\n", &ptr);

	ptr++;

	//char *p = a;  
	//
	//char **ptr = &p;
	//printf("p=%d\n",p);  
	//printf("ptr=%d\n",ptr);  
	//printf("*ptr=%d\n",*ptr);  
	//printf("**ptr=%c\n", **ptr);
	//ptr++;
	//printf("ptr=%d\n",ptr);  
	//printf("*ptr=%d\n",*ptr);  
	//printf("**ptr=%c\n", **ptr);


}

int max(int a, int b){
	return a + b;
}

//�ص�����
/*
����ָ��
����ָ����ָ������ָ�������
ͨ������˵��ָ�������ָ��һ�����͡��ַ��ͻ�����ȱ�����������ָ����ָ������
����ָ�������һ�㺯��һ�������ڵ��ú��������ݲ�����
*/
int testPoniterfun(int(*fun_ptr)(int, int), int m, int n){
	int sum = fun_ptr(m, n);
	return sum;
}

// �ص�����
void populate_array(int *array, size_t arraySize, int(*getNextValue)(void))
{
	for (size_t i = 0; i<arraySize; i++)
		array[i] = getNextValue();
}


// ��ȡ���ֵ 
int getNextRandomValue(void)
{
	return rand();
}