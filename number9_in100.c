#define _CRT_SECURE_NO_WARNINGS 1
void number9_in100(void)
{
	int i = 0;
	int num = 0;
	for (i = 1; i < 101; i++)
	{
		if (i % 10 == 9 || i / 10 == 9)
		{
			num = num + 1;
		}
	}
	printf("%d", num);
}