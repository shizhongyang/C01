
#include <stdio.h>

//1.C ������
/*
	��������һ��������������ͣ�����������ͬ���ڴ�λ�ô洢��ͬ���������͡������Զ���һ��
	���ж��Ա�Ĺ����壬�����κ�ʱ��ֻ����һ����Ա����ֵ���������ṩ��һ��ʹ����ͬ���ڴ�λ�õ���Ч��ʽ��
	���干����
	Ϊ�˶��干���壬������ʹ�� union ��䣬��ʽ�붨��ṹ���ơ�union ��䶨����һ���µ��������ͣ�
	���ж����Ա��union ���ĸ�ʽ���£�
	union [union tag]
	{
		member definition;
		member definition;
		...
		member definition;
	}
	union tag �ǿ�ѡ�ģ�ÿ�� member definition �Ǳ�׼�ı������壬���� int i; ���� float f; ����������Ч�ı������塣
	�ڹ����嶨���ĩβ�����һ���ֺ�֮ǰ��������ָ��һ��������������������ǿ�ѡ�ġ����涨��һ����Ϊ Data �Ĺ��������ͣ�
	��������Ա i��f �� str��
	union Data
	{
	int i;
	float f;
	char  str[20];
	} data;
	���ڣ�Data ���͵ı������Դ洢һ��������һ��������������һ���ַ���������ζ��һ����������ͬ���ڴ�λ�ã�
	���Դ洢����������͵����ݡ������Ը�����Ҫ��һ����������ʹ���κ����õĻ����û��Զ�����������͡�
	
	������ռ�õ��ڴ�Ӧ�㹻�洢�����������ĳ�Ա�����磬�������ʵ���У�Data ��ռ�� 20 ���ֽڵ��ڴ�ռ䣬
	��Ϊ�ڸ�����Ա�У��ַ�����ռ�õĿռ������ġ������ʵ������ʾ����Ĺ�����ռ�õ����ڴ��С��

	���ʹ������Ա
	Ϊ�˷��ʹ�����ĳ�Ա������ʹ�ó�Ա�����������.������Ա����������ǹ�����������ƺ�����Ҫ���ʵĹ������Ա֮���һ����š�
	������ʹ��union �ؼ��������干�������͵ı����������ʵ����ʾ�˹�������÷���

	������Ӧ�ó���
	ͨ���е����ݰ����õ�������:��Ϊ��֪���Է��ᷢһ��ʲô���������ù�����Ļ��ͺܼ��ˣ����弸�ָ�ʽ�İ���
	�յ���֮��Ϳ���ֱ�Ӹ��ݰ��ĸ�ʽȡ�����ݡ�
*/


union Data
{
	int i;
	float f;
	char  str[20];
};

//2.typedef
/*
	C �����ṩ�� typedef �ؼ��֣�������ʹ������Ϊ����ȡһ���µ����֡������ʵ��Ϊ���ֽ����ֶ�����һ������ BYTE��
	typedef unsigned char BYTE;
	��������Ͷ���֮�󣬱�ʶ�� BYTE ����Ϊ���� unsigned char ����д�����磺
	BYTE  b1, b2;
	���չ���������ʱ���д��ĸ���Ա������û�����������һ�������Ե���д������Ҳ����ʹ��Сд��ĸ�����£�
	typedef unsigned char byte;
	��Ҳ����ʹ�� typedef ��Ϊ�û��Զ������������ȡһ���µ����֡����磬�����ԶԽṹ��ʹ�� typedef ������һ���µ������������֣�
	Ȼ��ʹ������µ�����������ֱ�Ӷ���ṹ���������£�
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
	#define �� C ָ�����Ϊ�����������Ͷ���������� typedef ���ƣ��������������¼��㲻ͬ��
	typedef ������Ϊ���Ͷ���������ƣ�#define ��������Ϊ���Ͷ��������Ҳ��Ϊ��ֵ������������������Զ��� 1 Ϊ ONE��
	typedef ���ɱ�����ִ�н��͵ģ�#define �������Ԥ���������д���ġ�
	������ #define ����򵥵��÷���
*/

#define TRUE  1
#define FALSE 0

//�������ĺ�
//CPP һ��ǿ��Ĺ����ǿ���ʹ�ò������ĺ���ģ�⺯�������磬����Ĵ����Ǽ���һ������ƽ����
#define square(x) ((x) * (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

//void main(){
//	//1 ������
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
		��������ǿ��Կ���������� i �� f ��Ա��ֵ���𻵣���Ϊ��󸳸�������ֵռ�����ڴ�λ�ã�
		��Ҳ�� str ��Ա�ܹ���������ԭ������������������һ����ͬ��ʵ����
		���������ͬһʱ��ֻʹ��һ����������Ҳ��ʾ��ʹ�ù��������ҪĿ�ģ�
	*/

	//data.i = 10;
	//printf("data.i : %d\n", data.i);

	//data.f = 220.5;
	//printf("data.f : %f\n", data.f);  

	//strcpy(data.str, "C Programming");
	//printf("data.str : %s\n", data.str);  ���������������


	//2.typedef
	/*Book book;

	strcpy(book.title, "C �̳�");
	strcpy(book.author, "Runoob");
	strcpy(book.subject, "�������");
	book.book_id = 12345;

	printf("����� : %s\n", book.title);
	printf("������ : %s\n", book.author);
	printf("����Ŀ : %s\n", book.subject);
	printf("�� ID : %d\n", book.book_id);*/

//	printf("TRUE ��ֵ: %d\n", TRUE);
//	printf("FALSE ��ֵ: %d\n", FALSE);
//
//
//	int m = square(5);
//	printf("FALSE ��ֵ: %d\n", m);
//	getchar();
//}
