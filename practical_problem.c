#define _CRT_SECURE_NO_WARNINGS 1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
int compute(int money,int price)
{
	int number = 0;
	int number2 = 0;
	while (money)
	{
		number2 = money / price;
		number = number2+number;
		money = number2 / 2;
	}
	return number;
}