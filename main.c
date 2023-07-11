#define _CRT_SECURE_NO_WARNINGS 1
#include "main.h"
//int main()
//{
	//tcon_time_converter();
	//P_struct();
	//Sum_factorial
	//Sum_factorial2();
	//3binary_search();
	//mock_log();
	//timeforsheet();
	//campare();
	//cumloop();
	//number9_in100();
	//binary_search();
	//mutiple3();
	/*bubble_sort();
	bubble_sort2();*/
	//isprime100_200();
	// bissextile();
	 //Mcomdiv();
	//shutdown();
	//timeforsheet(12);
	/*printf("%d\n",i_fib(10));
	printf("%d", r_fib(10));*/
	//printf("%d", my_pow(5, 3));
	//printf("%d",DigitDum(1729));
	//char arr[7] = "abcdef";
	///*printf("%d", my_strlen(arr));
	//printf("%d", my_strlen2(arr));*/
	////printf("%d", factorial(5));
	////digital_pri(1234);
	// reverse_string2(arr);
	//int i;
	//for (i = 1; i <= 7; i++)
	//{
	//	printf("%c", arr[i - 1]);
	//}
	//return 0;
	// test for ex_change
		//int arr[10];
		//int arr2[10];
		//int i = 0;
		//for (i = 0; i <= 9; i++)
		//{
		//	scanf("%d", &arr[i]);
		//}
		//for (i = 0; i <= 9; i++)
		//{
		//	scanf("%d", &arr2[i]);
		//}
		//int sz = sizeof(arr) / sizeof(arr[1]);
		//ex_array(arr, arr2, sz);
		//bubble_sort(arr, sz);
		//for (i = 0; i < 10; i++)
		//{
		//	printf("%d, ", arr[i]);
		//}
		//printf("\n");
		//for (i = 0; i < 10; i++)
		//{
		//	printf("%d, ", arr2[i]);
		//}
	//test for re_array
		//int arr[10] = { 0 };
		//int i;
		//int sz = sizeof(arr) / sizeof(arr[1]);

		//for (i = 0; i < sz; i++)
		//{
		//	printf("%d", arr[i]);
		//	arr[i] = i + 1;
		//}
		//printf("\n");
		//re_array(arr,sz);
		//for (i = 0; i < sz; i++)
		//{
		//	printf("%d", arr[i]);
		//}
	// test for bubble_sort
//			int arr[10] = { 0 };
//			int i;
//			int sz = sizeof(arr) / sizeof(arr[1]);
//			for (i = 0; i < sz; i++)
//				{
//					scanf("%d", &arr[i]);
//				}
//			bubble_sort(arr, sz);
//			for (i = 0; i < 10; i++)
//				{
//					printf("%d, ", arr[i]);
//				}
//			printf("\n");
//			
//}
// 

	//int main() 
	//{
	//	int a;
	//	int i = 0;
	//	int arr[51] = { 0 };
	//	scanf("%d", &a);
	//	for (i = 0; i < a; i++)
	//	{
	//		scanf("%d ", &arr[i]);
	//	}
	//	int flag1 = 1;
	//	int flag2 = 1;
	//	i = 0;
	//	int j = 0;
	//	for (i = 0; i < a; i++)
	//	{
	//		for (j = 0; j < a - i; j++)
	//		{
	//			if (arr[j] > arr[j + 1])
	//				flag1 = 0;
	//		}
	//	}
	//	for (i = 0; i < a; i++)
	//	{
	//		for (j = 0; j < a - i; j++)
	//		{
	//			if (arr[j] < arr[j + 1])
	//				flag2 = 0;
	//		}
	//	}
	//	if (0 == flag1 && 0 == flag2)
	//		printf("unsorted");
	//	else 
	//		printf("sorted");
////		return 0;
////	
////
////}
//int main()
//{
//	//char arr[10000] = { 0 };
//	////scanf("%s", &arr);遇到空格会跳过
//	//get(arr);//可以解决这个问题
//	//re_str(arr);
//	//printf("%s", arr);
//	//return 0;
// 
// ******************************************************
//	int i = 1;
//	for (i = 1; i < 13; i+=2)
//	{
//		pristar(i);
//		printf("\n");
//	}
//	for (i = 13; i > 0; i-=2)
//	{
//		pristar(i);
//		printf("\n");
//	}
//}
//int main()
//{
//	/*int i = 0;
//	for (i = 1; i <= 10000; i++)
//	{
//		if (1 == Narcissistic_num(i))
//			printf("%d\n", i);
//	}
//	return 0;*/
//	printf("%d", compute(20,1));
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d", mcm(a, b));
//}
//char* arr[1000] = { NULL };
//int i = 0;
//int m = 0;
//void re_sten(char sen[])
//{
//	arr[m] = sen;
//	do
//	{
//		if (sen[i] == ' ')
//		{
//			arr[m] = sen + 1;
//			m++;
//		}
//		i++;
//	} while (sen[i] != '.');
//	arr[i] = sen + 1;
//}
//int main()
//{
//	char* arr[1000] = { NULL };//储存每个单词的首地址
//	int i = 0;//句子的字符数
//	int m = 0;//单词个数
//	char sen[1000] = { 0 };//储存单个单词
//	int number[10] = { 0 };//统计每个单词的个数
//	while ((sen[i] = getchar()) != '.')//储存并判断内容
//	{
//		i++;
//		(number[m])++;//计数
//		if (sen[i-1] == 32)//得到的是空格
//		{
//			arr[m] = (sen+i) - number[m];//找到首字母的地址
//			(number[m])--;//去除空格
//			m++;
//		}
//	}
//	arr[m] = (sen + i)-number[m];
//	(number[m])++;//最后一个单词以及句号
//	for (int i =m; i >= 0; i--)
//	{
//		for (int j = 0; j < number[i]; j++)
//		{
//			printf("%c", arr[i][j]);//输出单个单词
//		}
//		printf(" ");
//	}
//	return 0;
//}
//int main()
//{
//	//int str[] = { 2,3,4 };
//	//int sz = sizeof(str) / sizeof(str[0]);
//	//re_arr(str,sz);
//	//for (int i = 0; i < sz ; i++)
//	//{
//	//	printf("%d", str[i]);
//	//}
//	re_sentence2();
//	return 0;
//}
//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		if (Narcissistic_num(i) == 1)
//			printf("%d\n", i);
//
//	}
//
//
//	return 0;
//}
//test for is_increase
//判断有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//1为存在；0为不存在
//int main()
//{
//	int arr[col][row] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
//	printf("%d", is_increase(arr, 29));
//	return 0;
// }

//test for
//实现一个函数，可以左旋字符串中的k个字符。
//例如：ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//报错！！！！！,原因是越界访问，扩大str后成功
//用方法二成功
//int main()
//{
//	char str[10] = "ABCD";
//	int len = strlen(str);
//	char *tag=le_string(str, 3);
//	printf("%s", tag);
//	return 0;
//}

////test for 
////在屏幕上打印杨辉三角
//int main()
//{
//	print_yan(5);
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。


/*如：给定s1 = AABCD和s2 = BCDAA，返回1

给定s1 = abcd和s2 = ACBD，返回0.*/
//int main()
//
//{
//	char arr[12] = "abcd";
//	char tag[12] = "bcad";
//	int len = strlen(arr);
//	printf("%d", is_le_str(arr,tag,len));
//	return 0;
//}