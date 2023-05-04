#define _CRT_SECURE_NO_WARNINGS 1
void digital_pri(int x)
{
	if (x / 10 == 0)
		printf("%d\n", x);
	else
	{
		printf("%d\n", x % 10);
		digital_pri(x / 10);
	}
}