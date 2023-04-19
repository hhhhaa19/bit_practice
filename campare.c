#define _CRT_SECURE_NO_WARNINGS 1
void campare(void)
{
	int arr[10] = { 1,2,4,6,7,9,41,83,45,67 };
	int i = 0;
	int temp = arr[i];
	for (i = 0; i < 10; i++)
	{
		if (arr[i]>temp)
		{
			temp = arr[i];
		}
	}
	printf("max is %d", temp);
}