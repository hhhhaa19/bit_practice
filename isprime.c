#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
int isprime(int x)
{
	int a = 0;
	int b = sqrt(x) + 1;//ʹ��sqrt����ʱ�����⣬a<=sqrt,����������δ����!!!!�����ѷ��֣�ȱ��ͷ�ļ�
	for (a = 2;a <= b; a++)
	{
		int c = x % a;
		if (0 == c)
		{
			return 1;
		}
	}
		return 0;
		//������
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