#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
//����ʹ�ú���ָ������
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
 }

//int main()
//{//����һ������ָ������
//	int (*cum[2])(int, int) = { add,sub };
//	int choice = 0;
//	printf("��ѡ��1Ϊ�ӷ���2Ϊ����\n");
//	scanf("%d", &choice);
//	printf("����������\n");
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d", cum[choice](a, b));
//	return 0;
//}

//ʹ�ûص�����
//������ָ�����飬���Բ��涨�����С���������Ͼ���ʹ��
//�����ںϲ�ͬ����
//int cum( int (*p)(int, int))
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	return (p(a, b));
//}
//int main()
//{
//	printf("%d", cum(add));
//	return 0;
//}