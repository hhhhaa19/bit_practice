#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void tcon_time_converter(void)
{
    int a, b;
    long c;
    while (scanf("%d:%d %ld", &a, &b, &c) == 3)
    {//���´���������⣬û�н����������λ,
        /*int m = c / 60;
        int n = c - m * 60;
        printf("%02d:%02d", (a + m) % 24, (b + n) % 60);*/
     //�������,���Լ��ٱ���
        printf("%02d:%02d", (a+(c + b)/60) % 24, (b + c) % 60);
    }
    return 0;
}