#define _CRT_SECURE_NO_WARNINGS 1
void exchange(char* x, char* y)
{
	*x = (*x) ^ (*y);
	*y = (*x) ^ (*y);
	*x = (*x) ^ (*y);
}