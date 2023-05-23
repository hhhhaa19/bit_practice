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