#define _CRT_SECURE_NO_WARNINGS 1
//input an array, and a number amnong the array, return the index
void binary_search(void)
{
	int name[5] = { 1,2,3,4,8 };
	int a = 0;
	int n = 0;
	a = sizeof(name) / sizeof(name[0]);
	int left = 0;
	int right = a - 1;
	int mid = (left + right) / 2;
	printf("please give a number \n");
	scanf("%d", &n);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n == name[mid])
		{
			printf("%d is located at %d\n", n, mid+1);
			break;
		}
		else if (n > name[mid])
		{
			left = mid + 1;
		}
		else if (n < name[mid])
		{
			right = mid - 1;
		}
	}
	if (left==right +1)
		/*(left = right + 1)*/
		//=这里不是在比较，而是在赋值
	{
		printf("%d is not exsited\n", n);
	}
}