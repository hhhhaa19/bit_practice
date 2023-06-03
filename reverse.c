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
//逆序字符串，输入起始字符以及结束字符地址
void re_str(char* str, char* end)
{

	while (str < end)
	{
		exchange2(str, end);
		str++;
		end--;
	}
}
void re_sentence(void)
{
	char* arr[1000] = { NULL };//储存每个单词的首地址
	int i = 0;//句子的字符数
	int m = 0;//单词个数
	char sen[1000] = { 0 };//储存单个单词
	int number[10] = { 0 };//统计每个单词的个数
	//gets可以得到字符串
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
//先逆序整个字符串，在逆序局部单词

void re_sentence2(void)
{
	char str[100] = {0};
	gets(str);
	re_str(str, str +strlen(str) - 1);
	char* star = str;
	char* end = str;
	while ('\0'!=*end)
	{
		end++;
		if (*end == ' ')
		{
			re_str(star, end-1);
			star = end+1;
		}
		
	}
	re_str(star, end -1);
	printf("%s", str);
}
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，

//所有偶数位于数组的后半部分

void re_arr(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	//用选排的思路解决
	for (i = 0; i < sz ; i++)
	{
		for (j = 0; j < sz-1 ; j++)
		{
			if (0==arr[j]%2&&1==arr[j+1]%2)
				exchange2(&arr[j], &arr[j + 1]);
		}
	}
}