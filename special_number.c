#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
int Narcissistic_num(int x)
{
	int arr[10] = { 0 };
	int i = 0;
	int temp = x;
	int ans = 0;
	while (x != 0)
	{
		arr[i] = x % 10;
		i++;
		x /= 10;
	}
	int a = 0;
	for (a = i-1; a >= 0; a--)
	{
		ans = ans + pow(arr[a], 3);
	}
	if (ans == temp)
	{
		return 1;
	}
	else
		return 0;
}