#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#define N 3

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


//合并文件
void mergeImage(){
	FILE *fdest = fopen("D:/1_1.png", "wb");
	FILE *div = fopen("D:/div.txt", "r");


	if (fdest == NULL || div == NULL){
		perror("打开文件出错");
		return;
	}


	char tempName[60];
	FILE *tempFile;
	// 循环读出temp文件路径，并进行文件的合并
	while (fgets(tempName, 60, div))// fgets读取到字符串时返回非0，否则返回0
	{
		tempName[strlen(tempName) - 1] = '\0';// 去掉最后一个\n
		tempFile = fopen(tempName, "rb");
		if (tempFile == NULL)
		{
			printf("打开文件%s失败,", tempName);
			perror("出错原因");
			return;
		}


		// feof判断文件结尾
		// 当文件内部的位置指针指向文件结束时，并不会立即设置FILE结构中的文件结束标识，
		// 只有再执行一次读文件操作，才会设置结束标志，此后调用feof()才会返回为真。

		// 问题代码
		//while (!feof(tempFile))  // 问题代码,每次合并多写入一个EOF（-1）
		//{
		// fputc(fgetc(tempFile), fdest); // 将部分文件写入合并的文件
		//}


		printf("正在合并%s到新文件\n", tempName);

		//修正后的代码
		int ch = fgetc(tempFile); //在使用feof前先读取一个字符
		printf("%d\n", ch);
		while (!feof(tempFile)) //判断你上面读取的ch是否为结束符，feof在EOF的下一次读取才会返回1
		{
			fputc(ch, fdest);
			ch = fgetc(tempFile); //读取下一个字符  如果是EOF，那么进入下一次循环前就会停止
		}

		fclose(tempFile);
	}
	fclose(fdest);
	fclose(div);
}


//分割文件
void cutFile(){
	char *normal_path = "D:/1.png";

	char *write_path = "D:/3.png";

	FILE *fp = fopen(normal_path, "rb");
	FILE *write_fp = fopen(write_path, "wb");
	FILE *div = fopen("D:/div.txt", "w");
	if (fp == NULL || write_fp == NULL || div == NULL)
	{
		perror("打开错误");
		return;
	}

	fseek(fp, 0, SEEK_END);
	long filesize = ftell(fp);
	printf("%d\n", filesize);
	//printf("#%X,#%X\n", fp, write_fp);
	int blockLen = filesize / N;

	FILE *ftemp; //临时文件

	int i = 0;

	for (; i < N; i++)
	{
		char tName[20];
		char tdir[60] = "D:/";

		sprintf(tName, "部分%d.temp", i + 1);//生成文件名
		strcat(tdir, tName); //产生临时目录
		printf("%s\n", tdir);

		ftemp = fopen(tdir, "wb");
		if (ftemp == NULL)
		{
			perror("产生文件出错：");
			break;
		}
		fputs(tdir, div);
		fputc('\n', div);

		int offset = i*blockLen; //计算偏移量

		fseek(fp, offset, SEEK_SET);
		int count = 0; //统计写入ftemp的数量
		if (i == N - 1) blockLen = filesize - blockLen*(N - 1);
		while (count<blockLen && !feof(fp))
		{
			fputc(fgetc(fp), ftemp);
			count++;
		}
		printf("count:%d\n", count);
		fclose(ftemp);
	}


	//关闭流
	fclose(fp);
	fclose(div);
}











//字符指针  不能修改字符串
//void main(){
//
//	//内存连续排列
//	char *str = "Hello world";
//	//不可以修改
//	//*str = 's';
//
//	/*printf("%s\n", str);
//	printf("%#x\n", str);*/
//	mergeImage();
//
//	getchar();
//}




//