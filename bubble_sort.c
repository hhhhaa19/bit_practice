#define _CRT_SECURE_NO_WARNINGS 1
//form left to right, and increase
void exchange2(int* x, int* y)
{
	int temp = 0;
	temp = *y;
	*y = *x;
	*x = temp;
}
void bubble_sort(void)
{
	int arr[10] = {1,46,89,39,47,25,35,41,78,23};
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (arr[j] > arr[i])
			{
				exchange(&arr[i], &arr[j]);
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}
// very amazing output
void bubble_sort2(void)
{
	int arr[10] = { 1,46,89,39,47,25,35,41,78,23 };
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (arr[j] > arr[i])
			{
				exchange(&arr[i], &arr[j]);
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", arr[i]);
	}
}
