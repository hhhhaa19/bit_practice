#define _CRT_SECURE_NO_WARNINGS 1
void bissextile()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (1 == is_bissextile(year))
			count++;
	}
	printf("%d", count);
}
int is_bissextile (int year)
{
	if (0 == year % 4 && 0 != year % 100)
	{
		return 1;
	}
	else if (0 == year % 400)
	{
		return 1;
	}
	return 0;
}