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
//给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数
//要求：空间复杂度
//O(1)，时间复杂O(logn)
int GetNumberOfK(int* nums, int numsLen, int k) {
    int left = 0;
    int right = numsLen - 1;
    int mid = left + (right - left+1) / 2;
    while (left <= right)
    {
        mid = left + (right - left+1) / 2;
        if (nums[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }//找相同数的右端
    int tagright = left - 1;
    left = 0;
     right= numsLen - 1;
     mid = left + (right - left+1) / 2;
    while (left <= right)
    {
        mid = left + (right - left+1) / 2;
        if (nums[mid] >=k)
            right = mid - 1;
        else
            left = mid + 1;
    }//相同数的左端
    int tagleft = right + 1;
    return tagright - tagleft + 1;
}
//整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
//位操作符
int convertInteger(int A, int B) 
{
#if 0
    int ret = 0;
    //先异或两个数，然后一位位取出其中的1
    int xor = A ^ B;
    while (xor)
    {
        if (xor &1)//与1结果为1说明本身是1，说明A和B在这一位不同
            ret++;
        xor >>= 1;
    }
    return ret;
#endif
    //我们来看上面这个代码，他是一个典型的错误代码，他的结果是死循环，原因是右移操作符分为算数右移运算，算数右移时是用符号位填充的，而逻辑右移是用0填充的，oj时不断填充1导致死循环，而左移则是统一填0
    //修改时我们要限定位数
    int count = 0;
    int xor= A ^ B;
    for (int i = 0; i <= 31; i++)
    {
        if (xor &1)
            count++;
        xor >>= 1;
    }
    return count;
}
//给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
//请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 - 1 。
int dominantIndex(int* nums, int numsSize)
{
    int i = numsSize-1;
    int maxindex = 0;
    while (i>=0)
    {
        if (nums[i] > nums[maxindex])
            maxindex=i;
        i--;
    }
    i = numsSize - 1;
    while (i >= 0)
    {
        if (i != maxindex)
        {
            if (nums[maxindex] < nums[i] * 2)
                return -1;
        }
        i--;
    }
    return maxindex;
}
//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i, j;
    int max = (nums1Size > nums2Size ? nums1Size : nums2Size);
    int* ret = (int*)malloc(sizeof(int) * max);
    int k = 0;
    *returnSize=0;
    for (i = 0; i < nums1Size; i++)
    {
        for (j = 0; j < nums1Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                int m;
                for ( m = k-1; m >= 0; m--)
                {
                    if (ret[m] == nums1[i])
                        break;
                }
                if (m == -1)
                {
                    (*returnSize)++;
                    ret[k] = nums1[i];
                    k++;
                }
            }
        }
    }
    return ret;
}
//Lily上课时使用字母数字图片教小朋友们学习英语单词，每次都需要把这些图片按照大小（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过代码解决。
//Lily使用的图片使用字符"A"到"Z"、"a"到"z"、"0"到"9"表示。
int charcmp (const void* p1, const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}
void sort_ASCLL(char* str)
{
    //这里我们复习一下qsort和冒泡
  //qsort
#if 1
    int len = strlen(str);
    qsort(str,len,sizeof(char),charcmp);
#endif
    //冒泡
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {

            if (str[j] > str[j + 1])
            {
                char temp = str[j+1];
                str[j + 1] = str[j];
                str[j] = temp;
            }
        }
    }
}
//给你一个整数数组 nums ，请计算数组的 中心下标 。
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于
//数组最右端同样适用
int sum(int* nums, int left, int right)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum += nums[i];
    }
    return sum;
}
int pivotIndex(int* nums, int numsSize) 
{
    int index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int sumleft = sum(nums, 0, i-1);
        int sumright = sum(nums, i + 1, numsSize - 1);
        if (sumleft == sumright)
            return i;
    }
    return -1;
}
//编写一个函数，计算字符串中含有的不同字符的个数。字符在 ASCII 码范围内(0~127 ，包括 0 和 127)，换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
//例如，对于字符串 abaca 而言，有 a、b、c 三种不同的字符，因此输出 3 。
int sort(char* arr)
{//用桶排
    int* buc = (int*)malloc(sizeof(int) * 127);
    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        buc[arr[i]]=1;
    }
    int sum = 0;
    for (int j = 0; j <= 127; j++)
    {
        sum += buc[j];
    }
    return sum;
}
//给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n / 2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
int majorityElement(int* nums, int numsSize)
{
#if 0
    //桶排不行，因为有负数，而下标不能为负
    int* buc = (int*)calloc(50001,sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        buc[nums[i]]++;
    }
    for (int i = 0; i < 50001; i++)
    {
        if (buc[i] > numsSize / 2)
            return i;
    }
    return -1;
#endif
#if 0
    for (int i = 0; i < numsSize; i++)
    {
        int count = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
            if (count > numsSize / 2)
                return i;
        }
    }
    return -1;
#endif 
  /*  "23335" 首先从字符 2 开始计数 1 ，遇到 3 ，不同则 - 1 ，互拼消耗 重新从剩下的 "335" 开始的过程，这时
        候保存的字符为 3 ，遇到 3 则计数 + 1 ， 遇到5则计数 - 1 ，在计数不为 0 时，走到末尾保存的字符就是个数超过
        n / 2 的字符*/
    int i = 1;
    int sum = 1;
    int cur = nums[0];
    while (i < numsSize)
    {

        if (cur == nums[i])
        {
            sum++;
            i++;
        }
        else
        {
            sum--;
            i++;
            if (sum == 0)
            {
                cur = nums[i];
            }
        }
    }
    if (sum > 0)
        return cur;
}
//例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//自除数 不允许包含 0 。
int isself(int n);
int isself(int n)
{
    int num = n;
    int div = num % 10;
    while (num)
    {
        if (div == 0)
            return -1;
        if (n % div != 0)

            return -1;
        num /= 10;
        div = num % 10;

    }
    return 1;
}
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    *returnSize = 0;
    int* ret = (int*)calloc(right - left + 1,sizeof(int));
    for (int i = left; i <= right; i++)
    {
        if (isself(i) == 1)
        {
            ret[(*returnSize)++] = i;
        }
    }
    return ret;
}