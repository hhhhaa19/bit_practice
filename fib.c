#define _CRT_SECURE_NO_WARNINGS 1
int r_fib(int x)
{
	if (x == 1)
		return 1;
	else if (x == 2)
		return 1;
	else
		return r_fib(x - 2) + r_fib(x - 1);

}
int i_fib(int x)
{
	int pre1 = 1;
	int pre2 = 1;
	int present = 0;
	while (x >= 3)
	{
		present = pre1 + pre2;
		pre1 = pre2;
		pre2 = present;
		x--;
	}
	return present;
}