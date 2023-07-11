#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
//尝试使用函数指针数组
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
 }

//int main()
//{//创建一个函数指针数组
//	int (*cum[2])(int, int) = { add,sub };
//	int choice = 0;
//	printf("请选择：1为加法，2为减法\n");
//	scanf("%d", &choice);
//	printf("请输入数字\n");
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d", cum[choice](a, b));
//	return 0;
//}

//使用回调函数
//比起函数指针数组，可以不规定数组大小，参数符合均能使用
//类似于合并同类项
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