#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
void  reverse_string(char* string)
{
	int left = 0;
	int right = strlen(string)-1;
	while (left < right)
	{
		exchange(&string[left], &string[right]);
		left++;
		right--;
	}
}
//recursion
void reverse_string2(char* string)
{
	int len = strlen(string);
	char temp = 0;
	temp = *string;
	if (len == 2)
	{
		exchange(&string[0], &string[1]);
	}
	else
	{
		*string = string[len - 1];
		string[len - 1] = '\0';
		reverse_string2(string + 1);
	}
	string[len - 1] = temp;
}
void re_array(int* arr, int n)
{
	int i;
	for (i = 1; i <= n / 2; i++)
		exchange(&arr[i - 1], &arr[n - i]);
}
void re_str(char str[])
{
	int n = strlen(str);
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		exchange2(&str[left], &str[right]);
		left++;
		right--;
	}
}
void re_sentence(void)
{
	char* arr[1000] = { NULL };//储存每个单词的首地址
	int i = 0;//句子的字符数
	int m = 0;//单词个数
	char sen[1000] = { 0 };//储存单个单词
	int number[10] = { 0 };//统计每个单词的个数
	while ((sen[i] = getchar()) != '.')//储存并判断内容
	{
		i++;
		(number[m])++;//计数
		if (sen[i - 1] == 32)//得到的是空格
		{
			arr[m] = (sen + i) - number[m];//找到首字母的地址
			(number[m])--;//去除空格
			m++;
		}
	}
	arr[m] = (sen + i) - number[m];
	(number[m])++;//最后一个单词以及句号
	for (int i = m; i >= 0; i--)
	{
		for (int j = 0; j < number[i]; j++)
		{
			printf("%c", arr[i][j]);//输出单个单词
		}
		printf(" ");
	}
}