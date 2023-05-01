#define _CRT_SECURE_NO_WARNINGS 1
int DigitDum(int x)
{
	if (x / 10 == 0)
		return x;
	else
		return x % 10 + DigitDum(x / 10);
}