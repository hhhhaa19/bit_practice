#define _CRT_SECURE_NO_WARNINGS 1
int sum_5(int a)
{
	int arr[5] = { 0 };
	int sum = 0;
	int j = 0;
	arr[0] = a;
	for ( j = 1; j <5; j++)
	{
			arr[j] = a + arr[j-1] * 10;
		sum = sum + arr[j-1];
	}
	sum = sum + arr[j-1];
	return sum;
	
}