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
//输入年份，月份
//返回该月份的天数
//方法一：switch
int year_month(int year, int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (year % 400 == 0 || year % 4 == 0 && year != 100)
			return 29;
		else
			return 28;
		break;
	}
}
//方法二：数组（提前知道具体的值）
int year_month2(int year, int month)
{
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (year % 400 == 0 || year % 4 == 0 && year != 100))
		printf("%d", day[month -1] + 1);
	else
		printf("%d", day[month -1]);
}