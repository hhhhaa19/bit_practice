#define _CRT_SECURE_NO_WARNINGS 1
void pristar(x)
{
	char str[13] = { 0 };
	int i = 0;
	for (i = 0; i < 13; i++)
	{
		str[i] = '*';
	}
	if (13 != x)
	{
		for (i = 0; i <= (13 - 1 - x) / 2; i++)
		{
			str[i] = '$';
		}
		for ((i = (13 - 1 - x) / 2 + x + 1); i < 13; i++)
		{
			str[i] = '$';
		}
	}
	for (i = 0; i < 13; i++)
		printf("%c", str[i]);
}
//该任务是打印用“* ”组成的X形图案
void  print_x() 
{
	int number = 0;
	while (1 == scanf("%d", &number))
	{
		for (int i = 1; i <= number; i++)
		{
			for (int j = 1; j <= number; j++)
			{
				if (i == j || j == number + 1 - i)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");

		}

	}
	return 0;
}
//一个整数（2~20），表示直角三角形直角边的长度，即“*”的数量，也表示输出行数。
void pri_right_tri() {
	int number = 0;
	while (1 == scanf("%d", &number)) {
		for (int i = 1; i <= number; i++) {
			for (int j = 1; j <= number; j++) {
				if (j >= number - i + 1)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");

		}

	}
	return 0;
}