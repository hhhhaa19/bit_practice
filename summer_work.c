#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"
//Day 1
////�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
////1. �÷���һ�������б��������ӡ
////2. n Ϊ��������0 < n <= 5
int* printNumbers(int n, int* returnSize) {
    int num = pow(10, n) - 1;//��¼����
    *returnSize = num;
    int* ans = (int*)malloc(sizeof(int) * num);
    int i = num;//��¼�±�
    while (i)
    {
        ans[--i] = num--;
    }
    return ans;
}
//������������ڣ���������һ��ĵڼ��졣
//��֤���Ϊ4λ�������ںϷ���
int transdate(int year, int date, int month)
{
    int daynum = 0;
    int mon = month - 1;//�����±�
    int monday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (mon)
    {
        daynum += monday[--mon];
    }

    if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (month >= 3))//�����Ҵ��ڶ���
    {
        daynum++;//����
    }
    daynum += date;

    return daynum;
}
//��֤��Ƴ�˹���������κ�һ������m������������д��m����������֮�͡�
//����һ��������m��m��100������m������д��m����������֮�͵���ʽ�����
//����ֽ���string
char* Nikos(int num)
{
    int tag = pow(num, 3);
    int mid = tag / num;
}