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
   // int len = strlen(str);
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
//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
//解析：将乘积分为两次进行，第一次先将每个位置左边的数据乘积计算出来放到返回数组中，后边第二次循环
//将对应位置右边的数据乘积计算出来与返回数组对应位置的左半边乘积相乘得到结果
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* multileft = (int*)malloc(sizeof(int)*numsSize);
    int* multiright = (int*)malloc(sizeof(int) * numsSize);
    int* ret = (int*)malloc(sizeof(int) * numsSize);

    *returnSize = numsSize;
    int left = 1;//暂存前一个的值，避免重复计算
    //计算左侧的乘积
    for (int i = 0; i < numsSize; i++)
    {
        multileft[i] = left ;
        left *= nums[i];
    }
    int right = 1;
    //计算右侧的乘积,用倒着的方式可以避免除法
    for (int i = numsSize-1; i >=0; i--)
    {
        multiright[i] = right;
        left *= nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        ret[i] = multileft[i] * multiright[i];
    }
    return ret;
}
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
//二进制相加思想：与十进制相同，先计算不考虑进位的相加结果（ 0 + 0 得 0 ， 1 + 1 进位得 0 ， 1 + 0 得 1 ），使用
//异或可以取得； 然后计算相加的进位结果（同 1 的位置左移一位即可），使用相与后左移取得。
//示例5 0101 + 7 0111
//不考虑进位的相加结果 0101 ^ 0111 -> 0010
//相加的进位 0101 & 0111 -> 0101 因为进位左移得到 1010
//1010 + 0010
//不考虑进位的相加结果 1010 ^ 0010 -> 1000
//相加的进位 1010 & 0010 -> 0010 因为进位左移得到 0100
//1000 + 0100
//不考虑进位的相加结果 1000 ^ 0100 -> 1100
//相加的进位 1000 & 0100 -> 0000 进位为0结束运算
int Add(int num1, int num2) 
{
    int ans = 0;
    int cans = (num1 & num2) << 1;//carry bit ans
    int ucans = (num1 ^ num2);
    while (cans)
    {
        int temp = cans & ucans;
        ucans = cans ^ ucans;
        cans = temp;
        cans <<= 1;
    }
    return ucans;
}
//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出
//现在 nums 中的数字，并以数组的形式返回结果
//思路：下标与数字的高度重叠
//[2, 3, 3, 2, 4] 注意数组10个元素，值为[1 - 10]， 但是访问下标应该在[0 - 9]之内, 因此修改位置下标应该是值 - 1
//0号元素是2，则将1号位置置为对应负值[2, -3, 3, 2, 4]
//1号元素是3，则将2号位置置为对应负值[2, -3, -3, 2, 4]
//2号元素是 - 3，绝对值为3，将2号位置为负值，但是2号位已经重置过，不需要重置，否则会变正数[2, -3, -3, 2, 4]
//3号元素是 - 2，绝对值为2，将1号位置为负值，但是1号位已经重置过，不需要重置，否则会变正数[2, -3, -3, 2, 4]
//4号元素是4，则将3号位置置为对应负值[2, -3, -3, -2, 4]
//遍历数组得到0, 4两个位置的数据是大于0的，因为人家数值从1开始，因此 + 1后得到1， 5两个缺失的数字
// 下标与【1-n】的重合
//首先利用数据本身的正负来展现是否出现过，为正说明没有遍历到，即index中没有这个数，也就是下标的缺失，由于下标与【1-n】的重合，所以对应下标的缺失也就是对应数的缺失
//老师发作业，每个人发到作业，但作业不一定是自己的，但只要把其交给对应的人，那么每个人
//都有能有自己的作业。此时就明白谁没有作业了
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        int index = abs(nums[i]) - 1;
        nums[index] = (nums[index] > 0 ? (-nums[index]) : (nums[index]));
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            ret[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }
    return ret;
}
//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int count = 0;
    int max = 0;
    int cur = 0;
    while (cur < numsSize)
    {
        if (nums[cur] == 1)
        {
            count++;
        }
        else
        {
            if (count > max)
            max = count;
            count=0;
        }
        cur++;
    }
    if (count > max)
        max = count;
    return max;
}
//完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
//它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
//例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。
int isperfect(int n)
{
    int sum = 0;
    for (int i = 1; i < (int)sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            sum += n / i;
        }
    }
    if (sum == 2 * n)
        return 1;
    else
        return 0;
}
//输入一个整数，将这个整数以字符串的形式逆序输出
//程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
void restr(char* arr,int len)
{
    int i = 0;
    while (i < len / 2)
    {
        char temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
//char* reitoa(int n)
//{
//    char* arr = (char*)calloc(33, sizeof(char));
//    itoa(n, arr, 10);
//    restr(arr,strlen(arr));
//    return arr;
//}
//对字符串中的所有单词进行倒排。
//说明：
//1、构成单词的字符只有26个大写或小写英文字母；
//2、非构成单词的字符均视为单词间隔符；
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//4、每个单词最长20个字母；
char* resentence(char* arr)
{
    char* newarr = (char*)calloc(10000, sizeof(char));
    int len = strlen(arr);
    int i = len;
    int m = 0;
    while (i)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z')
        {
            newarr[m] = arr[i];
            m++;
            i--;
        }
        else
        {
            while ((!(arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z'))&& i>0)
            {
                i--;
            }
            m++;
            newarr[m] = ' ';
        }
    }
    int newlen = strlen(newarr);
    int start = 0;
    i = 0;
    int end = 0;
    while (i < newlen)
    {
        if (arr[i] == ' ')
        {
            end = i;
            restr(newarr + start, end - start);
            start = end+1;
        }
        i++;
    }
    restr(newarr + start, i - start + 1);
    return newarr;

}
//计算机有4个槽，每个槽放一个球，颜色可能是红色（R）、黄色（Y）、绿色（G）或蓝色（B）。例如，计算机可能有RGGB 4种（槽1为红色，槽2、3为绿色，槽4为蓝色）。作为用户，你试图猜出颜色组合。打个比方，你可能会猜YRGB。要是猜对某个槽的颜色，则算一次“猜中”；
//要是只猜对颜色但槽位猜错了，则算一次“伪猜中”。注意，“猜中”不能算入“伪猜中”。
int* masterMind(char* solution, char* guess, int* returnSize) 
{
   
        int* ret = (int*)calloc(2, sizeof(int));
        *returnSize = 2;
        int len = strlen(solution);
        int sol[4][4] = { 0 };//位数，颜色
        int ges[4][4] = { 0 };
        for (int i = 0; i < 4; i++)
        {
            if (*(solution + i) == 'R')
                sol[i][0] = 1;
            else if (*(solution + i) == 'Y')
                sol[i][1] = 1;
            else if (*(solution + i) == 'G')
                sol[i][2] = 1;
            else
                sol[i][3] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            if (*(guess + i) == 'R')
                ges[i][0] = 1;
            else if (*(guess + i) == 'Y')
                ges[i][1] = 1;
            else if (*(guess + i) == 'G')
                ges[i][2] = 1;
            else
                ges[i][3] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (sol[i][j] == 1 && ges[i][j] == 1)
                    ret[0]++;
            }

        }
        int solsum[4] = { 0 };
        int gessum[4] = { 0 };

        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                solsum[j] += sol[i][j];
                gessum[j] += ges[i][j];

            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (gessum[i] != 0 && solsum[i] != 0)
                ret[1] += gessum[i] > solsum[i] ? solsum[i] : gessum[i];
        }
        ret[1] -= ret[0];
        return ret;
    }


int fun(char* s)
{
    char* t = s;
    while (*t++);
    return(t - s);
}
//现在有一个长度为 n 的正整数序列，其中只有一种数值出现了奇数次，其他数值均出现偶数次，请你找出那个出现奇数次的数值。
int findodd(int len, int* nums)
{
    int ans = 0;
    int i = 0;
    while (i < len)
    {
        ans ^= nums[i];
        i++;
    }
    return ans;
}
//给定一个长度为n的数组 nums ，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可
int findPeakElement(int* nums, int numsLen)
{
    int left = 0;
    int right = numsLen - 1;
    int mid = left + (right - left ) / 2;
    while (left<right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid +1;
    }
    return left;
}
//给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列
//对分
int binsearch(int tag, int* numbers, int len)
{
    int left = 0;
    int right = len - 1;
    int mid = left + (right - left + 1) / 2;
    while (left < right)
    {
        if (numbers[mid] < tag)
            left = mid + 1;
        else if (numbers[mid] > tag)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}
int intcmp (const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}
//空间O(N),时间O(NlogN),先快排，在找数，一个个遍历过去，但要注意返回时要下标，所以下标->数->下标的思路,但目前知识不支持
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) 
{
    int i = 0;
    int* arr = (int*)calloc(2,sizeof(int));
    qsort(numbers,numbersLen,sizeof(int),intcmp);
    *returnSize = 2;
    while (i < numbersLen)
    {
        int find = target - numbers[i];
        if (binsearch(target, numbers, numbersLen) != -1)
        {

            arr[0] = numbers[i];
            arr[1] = find;
            break;
        }
        i++;
    }
    return arr;
}
//1、有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子
//都不死，问第 n 个月的兔子总数为多少？
//找规律得出是斐波那契数
int fib(int n)
{
    int num = 0;
    int num2 = 0;
    for (int i = 1; i <n; i++)
    {
        if (i <= 2)
            num = num2 = 1;
        else
        {
            num = num + num2;
            num2 = num + num2;
        }
    }
    return num + num2;
}