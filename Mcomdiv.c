#define _CRT_SECURE_NO_WARNINGS 1
//շת���
void Mcomdiv()
{
	int a, b;
	scanf("%d %d", &a,&b);
	//��������Ŀ�������������ֵ����������һЩ�жϣ�
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