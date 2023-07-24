#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
//test for some file opeation
//fgets&&fputs
//int main()
//{
//	FILE* pf = fopen("datd.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//input
//	char str[10] = { 0 };
//	fgets(str,10, pf);
//
//	//close file
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//
//fscanf&&fprintf

// struct student
//{
//	char name[10];
//	int age;
//	float weight;
//}stu1;
 ////typedef 后不能直接声明变量
//int main()
//{
//	FILE* pf = fopen("data.txt","r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return;
//	}
//	//可以改顺序的初始化方式
//	fscanf(pf, "%d %s %f", &stu1.age, stu1.name, &stu1.weight);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//fread&&fwrite
// struct student
//{
//	char name[10];
//	int age;
//	float weight;
// }stu1 ;
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return;
//	}
//	fread(&stu1, sizeof(struct student), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fseek&&ftell&&rewind
// //read end of file
//int main()
//{
//	FILE* pf = fopen("datd.txt", "w+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return;
//	}
//	fputs("I am not here, and you", pf);
//	fseek(pf,3,SEEK_SET);
//	fputc('r', pf);
//	rewind(pf);
//	char arr[20];
//	fgets(arr, 20, pf);//和scanf一样输入是遇空格停止
//	fprintf(stdout, "%s\n", arr);
//	int c;
//	while (c=fgetc( pf) != EOF)//注意pf这里的位置
//	{
//		fprintf(stdout,"%d",c);
//	}
////	return 0;
//}



