#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Max_in_4 (void)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int max = ((a > b ? a : b) > (c > d ? c : d) ? (a > b ? a : b) : (c > d ? c : d));
    printf("%d", max);
    return 0;
}