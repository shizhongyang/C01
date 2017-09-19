
#include <stdio.h>

//1.C 共用体
/*
	共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。您可以定义一个
	带有多成员的共用体，但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。
	定义共用体
	为了定义共用体，您必须使用 union 语句，方式与定义结构类似。union 语句定义了一个新的数据类型，
	带有多个成员。union 语句的格式如下：
	union [union tag]
	{
		member definition;
		member definition;
		...
		member definition;
	}
	union tag 是可选的，每个 member definition 是标准的变量定义，比如 int i; 或者 float f; 或者其他有效的变量定义。
	在共用体定义的末尾，最后一个分号之前，您可以指定一个或多个共用体变量，这是可选的。下面定义一个名为 Data 的共用体类型，
	有三个成员 i、f 和 str：
	union Data
	{
	int i;
	float f;
	char  str[20];
	} data;
	现在，Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。这意味着一个变量（相同的内存位置）
	可以存储多个多种类型的数据。您可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。
	
	共用体占用的内存应足够存储共用体中最大的成员。例如，在上面的实例中，Data 将占用 20 个字节的内存空间，
	因为在各个成员中，字符串所占用的空间是最大的。下面的实例将显示上面的共用体占用的总内存大小：

	访问共用体成员
	为了访问共用体的成员，我们使用成员访问运算符（.）。成员访问运算符是共用体变量名称和我们要访问的共用体成员之间的一个句号。
	您可以使用union 关键字来定义共用体类型的变量。下面的实例演示了共用体的用法：

	共用体应用场景
	通信中的数据包会用到共用体:因为不知道对方会发一个什么包过来，用共用体的话就很简单了，定义几种格式的包，
	收到包之后就可以直接根据包的格式取出数据。
*/


union Data
{
	int i;
	float f;
	char  str[20];
};

//2.typedef
/*
	C 语言提供了 typedef 关键字，您可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE：
	typedef unsigned char BYTE;
	在这个类型定义之后，标识符 BYTE 可作为类型 unsigned char 的缩写，例如：
	BYTE  b1, b2;
	按照惯例，定义时会大写字母，以便提醒用户类型名称是一个象征性的缩写，但您也可以使用小写字母，如下：
	typedef unsigned char byte;
	您也可以使用 typedef 来为用户自定义的数据类型取一个新的名字。例如，您可以对结构体使用 typedef 来定义一个新的数据类型名字，
	然后使用这个新的数据类型来直接定义结构变量，如下：
*/

typedef struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} Book;
//3.typedef vs #define
/*
	#define 是 C 指令，用于为各种数据类型定义别名，与 typedef 类似，但是它们有以下几点不同：
	typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
	typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
	下面是 #define 的最简单的用法：
*/

#define TRUE  1
#define FALSE 0

//参数化的宏
//CPP 一个强大的功能是可以使用参数化的宏来模拟函数。例如，下面的代码是计算一个数的平方：
#define square(x) ((x) * (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

//void main(){
//	//1 共用体
//	union Data data;
//
//	//Memory size occupied by data : 20
//	printf("Memeory, size occupied by data : %d\n", sizeof(data));
	/*
	data.i = 10;
	data.f = 220.5;
	strcpy(data.str,"c programming");

	printf("data.i : %d\n", data.i);
	printf("data.f : %f\n", data.f);
	printf("data.str : %s\n", data.str);
	
		data.i : 1917853763
		data.f : 4122360580327794860452759994368.000000
		data.str : C Programming
		在这里，我们可以看到共用体的 i 和 f 成员的值有损坏，因为最后赋给变量的值占用了内存位置，
		这也是 str 成员能够完好输出的原因。现在让我们再来看一个相同的实例，
		这次我们在同一时间只使用一个变量，这也演示了使用共用体的主要目的：
	*/

	//data.i = 10;
	//printf("data.i : %d\n", data.i);

	//data.f = 220.5;
	//printf("data.f : %f\n", data.f);  

	//strcpy(data.str, "C Programming");
	//printf("data.str : %s\n", data.str);  这样才能正常输出


	//2.typedef
	/*Book book;

	strcpy(book.title, "C 教程");
	strcpy(book.author, "Runoob");
	strcpy(book.subject, "编程语言");
	book.book_id = 12345;

	printf("书标题 : %s\n", book.title);
	printf("书作者 : %s\n", book.author);
	printf("书类目 : %s\n", book.subject);
	printf("书 ID : %d\n", book.book_id);*/

//	printf("TRUE 的值: %d\n", TRUE);
//	printf("FALSE 的值: %d\n", FALSE);
//
//
//	int m = square(5);
//	printf("FALSE 的值: %d\n", m);
//	getchar();
//}
