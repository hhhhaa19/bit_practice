#define _CRT_SECURE_NO_WARNINGS 1
void cumloop(void)
{
	int i = 0;
	float sum = 1.0f;
	for (i = 1; i <= 100; i++)
	{
		sum = 1.0 / i * pow(-1,i)+sum;
	}
	printf("%.10f", sum);
}