#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
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