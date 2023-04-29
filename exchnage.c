#define _CRT_SECURE_NO_WARNINGS 1
void exchange(int* x, int* y)
{
	*x = (*x) ^ (*y);
	*y = (*x) ^ (*y);
	*x = (*x) ^ (*y);
}