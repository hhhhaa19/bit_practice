#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"
//Day 1
////输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
////1. 用返回一个整数列表来代替打印
////2. n 为正整数，0 < n <= 5
int* printNumbers(int n, int* returnSize) {
    int num = pow(10, n) - 1;//记录数量
    *returnSize = num;
    int* ans = (int*)malloc(sizeof(int) * num);
    int i = num;//记录下标
    while (i)
    {
        ans[--i] = num--;
    }
    return ans;
}
//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
int transdate(int year, int date, int month)
{
    int daynum = 0;
    int mon = month - 1;//数组下标
    int monday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (mon)
    {
        daynum += monday[--mon];
    }

    if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (month >= 3))//闰年且大于二月
    {
        daynum++;//闰年
    }
    daynum += date;

    return daynum;
}
//验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
//输入一个正整数m（m≤100），将m的立方写成m个连续奇数之和的形式输出。
//输出分解后的string
char* Nikos(int num)
{
    int tag = pow(num, 3);
    int mid = tag / num;
}