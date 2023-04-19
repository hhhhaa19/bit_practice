#define _CRT_SECURE_NO_WARNINGS 1
void timeforsheet(void)
{
	int i,j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d  ", j, i);
			Sleep(200);
		}
		printf("\n");
	}
}