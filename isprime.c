#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
int isprime(int x)
{
	int a = 0;
	int b = sqrt(x) + 1;//使用sqrt函数时用问题，a<=sqrt,出错，问题尚未发现!!!!问题已发现，缺少头文件
	for (a = 2;a <= b; a++)
	{
		int c = x % a;
		if (0 == c)
		{
			return 1;
		}
	}
		return 0;
		//是质数
}
void isprime100_200(void)
{
	int i = 0;
	for (i = 101; i <= 200; i+=2)
	{
		if (isprime(i) == 0)
		{
			printf("%d ,", i);
		}
	}
}