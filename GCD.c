#define _CRT_SECURE_NO_WARNINGS 1
int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
int mcm(int a, int b)
{
	return a * b / gcd(a, b);
}