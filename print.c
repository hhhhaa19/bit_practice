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
//�������Ǵ�ӡ�á�* ����ɵ�X��ͼ��
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
//һ��������2~20������ʾֱ��������ֱ�Ǳߵĳ��ȣ�����*����������Ҳ��ʾ���������
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
//�������
// ����nCm,������
int per_comb(int m, int n)
{
	int temp = 1;
	int i = 0;
	int j = 0;
	if (m == 0)
	{
		return 1;
	}
	else
	{
		for (i = n; i >n - m; i--)
		{
			temp = temp * i;
		}
		int temp2 = 1;
		for (j = 1; j <= m; j++)
		{
			temp2 = temp2 * j;
		}
		return temp / temp2;
	}
}
//����Ļ�ϴ�ӡ�������
void print_yan(int num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j <= i-1; j++)
		{
			printf("%d ", per_comb(j, i-1));
		}
		printf("\n");
	}
}