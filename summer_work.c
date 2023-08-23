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
//方法1：直接打印
void Nikos(int num)
{
    int tag = pow(num, 3);
    int mid = tag / num;
    if (mid % 2 == 0)//偶数个
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
//方法2：用sprintf存
char* Nikos2(int num)
{

}
//等差数列 2，5，8，11，14。。。。
//（从 2 开始的 3 为公差的等差数列）
//输出求等差数列前n项和
int evendiff(int n)
{
    int ret = 0;
    int add = 2;//加数
    while (n--)
    {
        ret += add;
        add += 3;
    }
    return ret;
}

//首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
//0即不是正整数，也不是负数，不计入计算。如果没有正数，则平均值为0。
void  ave_num(int num, int* arr, int* negnum,int* plusnum,int* sum)
{
    *negnum = 0;
    *plusnum = 0;
    *sum = 0;
    int i = 0;//下标
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
//有一个长度为 n 的非降序数组，比如[1, 2, 3, 4, 5] ，将它进行旋转，即把一个数组最开始的若干个元素搬到数组
//的末尾，变成一个旋转数组，比如变成了[3, 4, 5, 1, 2] ，或者[4, 5, 1, 2, 3] 这样的。请问，给定这样一个旋转数组，求数
//组中的最小值。
//首先如果用直接遍历时间复杂度为O(N),失去了有序的意义，所以这里使用二分法，时间复杂度为O(logN)
int minNumberInRotateArray(int* nums, int numsLen) {
    int left = 0;
    int right = numsLen - 1;
    int mid = left + (right - left) / 2;
    //尾巴上加一个1000,防止溢出
    while (left <= right)
    {
        mid = (left + right + 1) / 2;
        if (nums[mid] < nums[right])
        {
            left = mid + 1;
        }
        else if(nums[mid]>nums[right])
        {
            right = mid ;
        }
        else
        {
            right--;
        }
    }
    return nums[left];
}
//集合s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
#if 0
//找重复
    //总思路：a=a^b;b=a^b;a=a^b;交换的思路
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
    //这种方式把两个剔除来
#endif
    //因为不支持变长数组，我们选择创空间，并
    int* arr = (int*)calloc(numsSize,sizeof(int));
    int* ret = (int*)calloc(2,sizeof(int));
    //这里相当于桶排
    int i = 0;
    int sum = 0;
    int realsum = 0;
    for (i = 0; i < numsSize; i++)
    {
        arr[nums[i]]++;
        if (arr[nums[i]] == 2)
        {
            ret[1] = nums[i];
        }
        sum += nums[i];
        realsum += i;
    }
    ret[2] = realsum - (sum - ret[1]);
    return ret;
}
//
//小明同学最近开发了一个网站，在用户注册账户的时候，需要设置账户的密码，为了加强账户的安全性，小明对密码强度有一定要求：
//1. 密码只能由大写字母，小写字母，数字构成；
//2. 密码不能以数字开头；
//3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；
//4. 密码长度至少为8
//现在小明受到了n个密码，他想请你写程序判断这些密码中哪些是合适的，哪些是不合法的。
int islegal(char* str)
{
    int len = (int)strlen(str);
    if (len < 8)
        return -1;
    int type[3] = { 0 };
    for (int i = 0; i < len; i++)
    {
        char temp = str[i];
        if (0 == i && (temp >= '0' && temp <= '9'))
        {
            return -1;
        }
        if ((temp >= '0' && temp <= '9') || (temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            if (temp >= '0' && temp <= '9')
                type[0] = 1;
            if (temp >= 'a' && temp <= 'z')
                type[1] = 1;
            if (temp >= 'A' && temp <= 'Z')
                type[2] = 1;
        }
        else
        {
            return -1;
        }
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += type[i];
    }
    if (sum >= 2)
        return 0;
    else
        return -1;
}
