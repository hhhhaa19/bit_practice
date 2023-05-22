#define _CRT_SECURE_NO_WARNINGS 1
int diffinbin(int x, int y)
{
	int a = 0;
	int b = 0;
	int count = 0;
	while (x != 0 && y != 0)
	{
		 a = x & 1;
		 b = y & 1;
		if (a != b)
		{
			count++;
		}
		x >>= 1;
		y >>= 1;
	}
	return count;
}