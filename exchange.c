#define _CRT_SECURE_NO_WARNINGS 1
void exchange(char* x, char* y)
{
	*x = (*x) ^ (*y);
	*y = (*x) ^ (*y);
	*x = (*x) ^ (*y);
}
void exchange2(char* x, char* y)
{
	char temp = 0;
	temp = *y;
	*y = *x;
	*x = temp;
}

void ex_array (int* x, int* y,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		exchange2(&x[i], &y[i]);

}