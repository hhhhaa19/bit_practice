#define _CRT_SECURE_NO_WARNINGS 1
#define col 5//�ܹ�����
#define row 5//ÿ��5��
//�ж���һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//1Ϊ���ڣ�0Ϊ������
//���ﳢ��ʹ������ָ��
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