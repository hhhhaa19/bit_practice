#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
int my_pow(int x, int n)
{
	if (n == 1)
		return x;
	else
		return x * my_pow(x, n - 1);
}
