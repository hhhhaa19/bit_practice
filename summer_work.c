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
//����1��ֱ�Ӵ�ӡ
void Nikos(int num)
{
    int tag = pow(num, 3);
    int mid = tag / num;
    if (mid % 2 == 0)//ż����
    {
        int i = num/2;
        while (i)
        {
            printf("%d+", mid + 1 - i * 2);
            i--;
        }
        i = 0 ;
        while (i<num/2-1)
        {
            printf("%d+", mid + 1 + i * 2);
            i++;
        }
        printf("%d", mid + 1 + i * 2);
    }
    else
    {
        int i = num / 2;
        while (i)
        {
            printf("%d+", mid  - i * 2);
            i--;
        }
        i = 0;
        while (i < num / 2 )
        {
            printf("%d+", mid  + i * 2);
            i++;
        }
        printf("%d", mid  + i * 2);
    }
}
//����2����sprintf��
char* Nikos2(int num)
{

}
//�Ȳ����� 2��5��8��11��14��������
//���� 2 ��ʼ�� 3 Ϊ����ĵȲ����У�
//�����Ȳ�����ǰn���
int evendiff(int n)
{
    int ret = 0;
    int add = 2;//����
    while (n--)
    {
        ret += add;
        add += 3;
    }
    return ret;
}

//��������Ҫ�������������n��Ȼ������n�����������Ϊn�������и����ĸ�������������������ƽ��ֵ���������һλС����
//0��������������Ҳ���Ǹ�������������㡣���û����������ƽ��ֵΪ0��
void  ave_num(int num, int* arr, int* negnum,int* plusnum,int* sum)
{
    *negnum = 0;
    *plusnum = 0;
    *sum = 0;
    int i = 0;//�±�
    while (i<num)
    {
        if (arr[i] < 0)
        {
            (*negnum)++;
        }
        else if(arr[i]>0)
        {
            (*plusnum)++;
            *sum += arr[i];
        }
        i++;
    }
}
//��һ������Ϊ n �ķǽ������飬����[1, 2, 3, 4, 5] ������������ת������һ�������ʼ�����ɸ�Ԫ�ذᵽ����
//��ĩβ�����һ����ת���飬��������[3, 4, 5, 1, 2] ������[4, 5, 1, 2, 3] �����ġ����ʣ���������һ����ת���飬����
//���е���Сֵ��
//���������ֱ�ӱ���ʱ�临�Ӷ�ΪO(N),ʧȥ����������壬��������ʹ�ö��ַ���ʱ�临�Ӷ�ΪO(logN)
int minNumberInRotateArray(int* nums, int numsLen) {
    int left = 0;
    int right = numsLen - 1;
    int mid = (left + right + 1) / 2;
    //β���ϼ�һ��1000,��ֹ���
    nums[numsLen] = 10000;
    while (left <= right)
    {
        mid = (left + right + 1) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (nums[mid] <= nums[right])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return nums[left];
}
//����s ������ 1 �� n �����������ҵ��ǣ���Ϊ���ݴ��󣬵��¼�������ĳһ�����ָ����˳��˼������������һ�����ֵ�ֵ�����¼��� ��ʧ��һ������ ���� ��һ�������ظ� ��
//����һ������ nums �����˼��� S ���������Ľ����
//�����ҳ��ظ����ֵ����������ҵ���ʧ�����������������������ʽ���ء�
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
//���ظ�
    //��˼·��a=a^b;b=a^b;a=a^b;������˼·
    int tep = 0;
    int sum = 0;
    int tepsum = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        tep ^= i;
        sum += i;
    }
    for (int j = 0; j < numsSize; j++)
    {
        tep ^= nums[j];
        tepsum += nums[j];
    }
    int loss = sum - (tepsum - tep);
    int* ans[2] = { tep, loss };
}