#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
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