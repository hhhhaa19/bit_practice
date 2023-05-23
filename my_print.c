#define _CRT_SECURE_NO_WARNINGS 1
void printarr(int arr[],int  sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", *(arr + i));
	}
}