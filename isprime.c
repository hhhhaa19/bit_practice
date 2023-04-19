#define _CRT_SECURE_NO_WARNINGS 1
int isprime(int x)
{
	int a = 0;
	for (a = 2;a <= sqrt(x) + 1; a++)
	{
		if (x%a)
		{
			return 1;
		}
	}
	if (a == sqrt(x) + 2)
	{
		return 0;
	}
}
void isprime100_200(void)
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (isprime(i) == 0)
		{
			printf("%d ,", i);
		}
	}
}