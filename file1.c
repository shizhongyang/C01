#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int x = 20; //全局变量的声明

/* 字符串的操作
	1	strcpy(s1, s2);
	复制字符串 s2 到字符串 s1。
	2	strcat(s1, s2);
	连接字符串 s2 到字符串 s1 的末尾。
	3	strlen(s1);
	返回字符串 s1 的长度。
	4	strcmp(s1, s2);
	如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
	5	strchr(s1, ch);
	返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
	6	strstr(s1, s2);
	返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置
*/


void Pros(char* a, int b, int e, char et); // 形参，只声明
void test();  
void testStu();
void testFile(); //写文件  函数声明
void readFile(); // 读文件
void testSeek(); //测试fseek函数

void testHong();//测试宏
double  average(int num, ...); //可变参数
void testZhizhen(); //测试指针

int max(int x, int y);
//typedef int(*fun_ptr)(int, int); // 声明一个指向同样参数、返回值的函数指针类型
int testPoniterfun(int (*fun_ptr)(int,int),int m,int n); //这两个方法测试函数的回调
//int testPoniterfun(int(*fun_ptr)(int x, int y), int m, int n); //这个和上面的含义是一样的


int getNextRandomValue(void);
void populate_array(int *array, size_t arraySize, int(*getNextValue)(void));

//  定义结构
/*  为了定义结构，您必须使用 struct 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下：
	struct [structure tag]
	{
	member definition;
	member definition;
	...
	member definition;
	} [one or more structure variables];

	structure tag 是可选的，每个 member definition 是标准的变量定义，
	比如 int i; 或者 float f; 或者其他有效的变量定义。在结构定义的末尾，最后一个分号之前，
	您可以指定一个或多个结构变量，这是可选的。下面是声明 Book 结构的方式：

	为了访问结构的成员，我们使用成员访问运算符（.）。成员访问运算符是结构变量名称和我们要访问的
	结构成员之间的一个句号。您可以使用 struct 关键字来定义结构类型的变量。下面的实例演示了结构的用法：
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

/*  结构作为函数参数 
	您可以把结构作为函数参数，传参方式与其他类型的变量或指针类似。您可以使用上面实例中的方式来访问结构变量：
*/
//void printBook(struct Books book);


/*  指向结构的指针
	您可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似，如下所示：
	struct Books *struct_pointer;
	现在，您可以在上述定义的指针变量中存储结构变量的地址。为了查找结构变量的地址，请把 & 运算符放在结构名称的前面，如下所示：
	struct_pointer = &Book1;
	为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符，如下所示：
	struct_pointer->title;
*/
void printBook(struct Books *book);

//位域
/*  
	有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位。例如在存放一个开关量时，只有 0 和 1 两种状态，用 1 位二进位即可。为了节省存储空间，并使处理简便，C 语言又提供了一种数据结构，称为"位域"或"位段"。
	所谓"位域"是把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。
	典型的实例：
	用 1 位二进位存放一个开关量时，只有 0 和 1 两种状态。
	读取外部文件格式——可以读取非标准的文件格式。例如：9 位的整数。

	位域的定义和位域变量的说明
	位域定义与结构定义相仿，其形式为：
	struct 位域结构名
	{

	位域列表

	};

	其中位域列表的形式为：
	类型说明符 位域名: 位域长度

	例如：
	struct bs{
		int a:8;
		int b:2;
		int c:6;
	}data;  说明 data 为 bs 变量，共占两个字节。其中位域 a 占 8 位，位域 b 占 2 位，位域 c 占 6 位。


	让我们再来看一个实例：
	struct packed_struct {
		unsigned int f1:1;
		unsigned int f2:1;
		unsigned int f3:1;
		unsigned int f4:1;
		unsigned int type:4;
		unsigned int my_int:9;
	} pack; //在这里，packed_struct 包含了 6 个成员：四个 1 位的标识符 f1..f4、一个 4 位的 type 和一个 9 位的 my_int。

	对于位域的定义尚有以下几点说明：
	一个位域必须存储在同一个字节中，不能跨两个字节。如一个字节所剩空间不够存放另一位域时，应从下一单元起存放该位域。也可以有意使某位域从下一单元开始。例如：
	struct bs{
		unsigned a:4;
		unsigned  :4;     空域 
		unsigned b : 4;    从下一单元开始存放 
		unsigned c : 4
	}
	在这个位域定义中，a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位。
	由于位域不允许跨两个字节，因此位域的长度不能大于一个字节的长度，也就是说不能超过8位二进位。如果最大长度大于计算机的整数字长，一些编译器可能会允许域的内存重叠，另外一些编译器可能会把大于一个域的部分存储在下一个字中。
	位域可以是无名位域，这时它只用来作填充或调整位置。无名的位域是不能使用的。例如：
	struct k{
		int a : 1;
		int : 2;     该 2 位不能使用 
		int b : 3;
		int c : 2;
	};
	从以上分析可以看出，位域在本质上就是一种结构类型，不过其成员是按二进位分配的。

	位域的使用
	位域的使用和结构成员的使用相同，其一般形式为：

		位域变量名.位域名
		位域变量名->位域名

	位域允许用各种格式输出。

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



// 字符串常量化运算符（#）  宏延续运算符（\）
#define  message_for(a, b)  \
	printf(#a " and " #b ": We love you!\n")

//递归
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
//	printf("var1 变量的地址： %p\n", &var1);
//	printf("var2 变量的地址： %p\n", &var2);
//
//	/* 在主函数中的局部变量声明 */
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//
//
//	//int var = 20;
//	//int *ip; //指针变量声明
//	//ip = &var;
//	//printf("address of var varable :%x\n", &var);
//	///* 在指针变量中存储的地址 */
//	//printf("Address stored in ip variable: %x\n", ip);
//	//*ip = 30;  //指向30
//	///* 使用指针访问值 */
//	//printf("Value of *ip variable: %d\n", *ip);
//
//	//Pros("Hello", 5, 66666, 'a'); // 实参，已赋值
//
//	//char str1[12] = "Hello";
//	//char str2[12] = "World";
//	//char str3[12];
//	///* 复制 str1 到 str3 */
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
//	//	printf("%d 的阶乘为 %d\n", i, factorial(i));
//
//	//printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2, 3, 4, 5));
//
//	//testZhizhen();
//
//	/*int s = testPoniterfun(max,3, 4);
//	printf("s的值为 %d\n", s);*/
//
//	/*int myarray[10];
//	populate_array(myarray, 10, getNextRandomValue);
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", myarray[i]);
//	}
//	printf("\n");*/
//
//	//bit.a = 1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
//	//bit.b = 7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
//	//bit.c = 15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
//	//printf("%d,%d,%d\n", bit.a, bit.b, bit.c);    /* 以整型量格式输出三个域的内容 */
//
//	printf("debug_size1_t size=%lu,debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
//
//	system("pause");
//
//	//return 0;
//
//}


/*按照偏移值访问函数形参内容实验*/
//二级指针
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
	/* 输出 Book1 信息 */
	printf("Book 1 title : %s\n", book1.title);

}

//void printBook(struct Books book)
//{
//	printf("Book title : %s\n", book.title);
//	printf("Book author : %s\n", book.author);
//	printf("Book subject : %s\n", book.sbject);
//	printf("Book book_id : %d\n", book.book_id);
//}

//为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符，如下所示：
void printBook(struct Books *book)
{
	printf("Book- title : %s\n", book->title);
	printf("Book- author : %s\n", book->author);
	printf("Book- subject : %s\n", book->sbject);
	printf("Book- book_id : %d\n", book->book_id);
}


//测试typedef
void testStu(){
	Stu stu;
	strcpy(stu.gender, "男");
	strcpy(stu.name, "hello");
	printf("姓名 : %s\n", stu.name);
}

//文件的读写
void testFile(){
	FILE *fp = NULL;

	//FILE *fopen( const char * filename, const char * mode ); 打开文件 
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

	//首先，fscanf() 方法只读取了 This，因为它在后边遇到了一个空格。
	//其次，调用 fgets() 读取剩余的部分，直到行尾。最后，调用 fgets() 完整地读取第二行。
}


void testSeek(){
	FILE *fp = NULL;
	fp = fopen("D:/elinkdeyuan/test.txt", "r+");  // 确保 test.txt 文件已创建
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

	/* 为 num 个参数初始化 valist */
	va_start(valist, num);

	/* 访问所有赋给 valist 的参数 */
	for (i = 0; i < num; i++)
	{
		sum += va_arg(valist, int);
	}
	/* 清理为 valist 保留的内存 */
	va_end(valist);

	return sum / num;
}


void testZhizhen(){
//	char a[20];
	char a[20] = "You_are_a_girl";

	//char *ptr = a;  
	//char *ptr = &a;
	char *ptr = &a[0];  //上面三种写法是结果是一致的都是得到数组的首地址
	//int *ptr = (int *)a; //强制类型转换并不会改变a 的类型  
	printf("ptr指针  :%d\n", ptr); 
	printf("ptr指针2  :%c\n", *ptr);
	printf("ptr指针&  :%d\n", &ptr);

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

//回调函数
/*
函数指针
函数指针是指向函数的指针变量。
通常我们说的指针变量是指向一个整型、字符型或数组等变量，而函数指针是指向函数。
函数指针可以像一般函数一样，用于调用函数、传递参数。
*/
int testPoniterfun(int(*fun_ptr)(int, int), int m, int n){
	int sum = fun_ptr(m, n);
	return sum;
}

// 回调函数
void populate_array(int *array, size_t arraySize, int(*getNextValue)(void))
{
	for (size_t i = 0; i<arraySize; i++)
		array[i] = getNextValue();
}


// 获取随机值 
int getNextRandomValue(void)
{
	return rand();
}