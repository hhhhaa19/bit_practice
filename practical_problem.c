#define _CRT_SECURE_NO_WARNINGS 1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
int compute(int money)
{
	int total = money;
	int empty =money;
	while (empty>=2)
	{
		total += money;
		empty =empty / 2+empty%2;//improtant!!!
	}
	return total;
}