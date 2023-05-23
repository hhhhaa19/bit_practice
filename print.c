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