#define _CRT_SECURE_NO_WARNINGS 1
//form left to right, and increase

void bubble_sort(int * arr,int sz)
{
	int i, j;
	for (i = 0; i < sz-1; i++)
	{
		for (j = i; j < sz; j++)
		{
			if (arr[j] > arr[i])
			{
				exchange2(&arr[i], &arr[j]);//exchange two number
			}
		}
	}
}
// very amazing output
//exactly it is select sort
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
				exchange2(&arr[i], &arr[j]);
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", arr[i]);
	}
}
