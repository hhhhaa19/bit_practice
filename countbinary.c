#define _CRT_SECURE_NO_WARNINGS 1
int ocuntbinary(int x)
{
	int n = 1;
	int count =0;
	while (x>=n)
	{
		if (x & n == 1)
			count++;
		x = x >> 1;
	}
	return count;
}