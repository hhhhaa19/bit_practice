#define _CRT_SECURE_NO_WARNINGS 1
//辗转相减
void Mcomdiv()
{
	int a, b;
	scanf("%d %d", &a,&b);
	//可以用三目操作符来求最大值！！（代替一些判断）
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	printf("%d", a);

}