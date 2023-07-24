#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
//^相同出1，相异出0
int find_single2(int* arr, int sz)
{
	assert(arr);
	int ret = arr[0];
	for (int i = 1; i < sz; i++)
	{
		 ret ^= arr[i];
	}
	return ret;
}
void find_single(int arr[], int len, int* p1, int* p2)
{
	assert(arr&&p1&&p2);
	int i = 0;
	int pos = 0;
	int temp = find_single2(arr,len);
	//找到第几位为1，说明两个single在这一位不同，以这一位去找
	for (i = 0; i < 32; i++)
	{
		if ((temp >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	int single1 = 0;
	int single2 = 0;
	for (i = 0; i < len; i++)
	{
		if ((arr[i] >> pos) & 1 == 1)//把目标数字向右移pos个位置，然后分组
		{
			single1 ^= arr[i];
		}
	}
	single2 = temp ^ single1;
	*p1 = single1;
	*p2 = single2;

}