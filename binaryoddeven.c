#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
void binaryoddeven(int x)
{
int y = x;
int i = 1;
int odd[16] = { 0 };
int even[16] = { 0 };
for (i = 0; i <= 15; i++)
{
	odd[i] = x & 1;
	x = x >> 2;
}
y = y >> 1;

for (i = 0; i <= 15; i++)
{
	even[i] = y & 1;
	y = y >> 2;
}

for (i = 15; i >= 0; i--)
{
	printf("%d", odd[i]);
}
printf("\n");
for (i = 15; i >= 0; i--)
{
	printf("%d", even[i]);
}

}