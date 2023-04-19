#define _CRT_SECURE_NO_WARNINGS 1
//two approches to solve sum of factorial
//recusive
void Sum_factorial(void)
{
	int x = 0;
	while (scanf("%d", &x) != -1)
	{	
		printf("%d",help_Sum_factorial(x));
	}
}
int help_Sum_factorial(int x)
{
		if (x == 1)
		{
			return 1;
		}
		else
		{
			return x * factorial(x - 1) + help_Sum_factorial(x - 1);
		}
}
int factorial(int x)
{
	if (x == 1)
	{
		return 1;
	}
	else
	{
		return x * factorial(x - 1) ;
	}
}
 //loop
void Sum_factorial2(void)
{
	int x = 0;
	while (scanf("%d", &x) != -1)
	{
		int i = 0;
		int j = 0;
		int temp = 0;
		int sum = 0;
		for (j = 1; j <= x; j++)
		{
			temp = 1;
			for (i = 1; i <= j; i++)
			{
				temp = i * temp;
			}
			sum = sum + temp;
		}
		printf("%d", sum);
	}
}