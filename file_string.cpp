#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
//字符数组  可以修改
//void main(){
//	//char str[] = { 'c', 'h', 'i','\0' };  //第一种字符串
//	//char str[6] = { 'c', 'h', 'i', 'n','a' }; //第二种方式
//	char str[10] = "china";  //第三种
//	//可以先修改
//	str[0] = 's';
//
//	printf("%s\n", str);
//	printf("%#x\n", str);
//	getchar();
//}

//字符指针  不能修改字符串
void main(){

	//内存连续排列
	char *str = "Hello world";
	//不可以修改
	//*str = 's';

	/*printf("%s\n", str);
	printf("%#x\n", str);*/

	char *normal_path = "D:/1.png";

	char *write_path = "D:/3.png";

	FILE *fp = NULL;
	fp = fopen(normal_path, "rb");
	FILE *write_fp = fopen(write_path, "wb");

	//printf("#%X,#%X\n", fp, write_fp);
	/*fseek(fp, 0, SEEK_END);
	long filesize = ftell(fp);*/

	//复制
	int buff[50]; //缓冲区域
	int len = 0; //每次读到的数据长度
	while ((len = fread(buff, sizeof(int) , 50 , fp)) != 0){
		//将读到的内容写入新的文件
		fwrite(buff, sizeof(int), len, write_fp);
		fseek(write_fp, 0, SEEK_END);
		long filewsize = ftell(write_fp);
		printf("%d\n", filewsize);
	}
	//关闭流
	fclose(fp);
	fclose(write_fp);
	//printf("%d\n", filesize);
	getchar();
}