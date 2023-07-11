#define _CRT_SECURE_NO_WARNINGS 1
#define col 5//总共五排
#define row 5//每排5个
//判断有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//1为存在；0为不存在
//这里尝试使用数组指针
int is_increase(int (*arr)[col], int target)
{
	int left = 1;
	int right = col * row;
	int mid = (left + right) / 2 + 1;
	while (left <= right)
	{
		mid = (left + right) / 2 + 1;
		if (target == arr[(mid - 1) / row][mid - ((mid - 1) / row) * row - 1])
		{
			return 1;
		}
		else if (target < arr[(mid - 1) / row][mid - ((mid - 1) / row) * row - 1])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (left > right)
		return 0;
}