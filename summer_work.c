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
    int mid = left + (right - left) / 2;
    //β���ϼ�һ��1000,��ֹ���
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
//����s ������ 1 �� n �����������ҵ��ǣ���Ϊ���ݴ��󣬵��¼�������ĳһ�����ָ����˳��˼������������һ�����ֵ�ֵ�����¼��� ��ʧ��һ������ ���� ��һ�������ظ� ��
//����һ������ nums �����˼��� S ���������Ľ����
//�����ҳ��ظ����ֵ����������ҵ���ʧ�����������������������ʽ���ء�
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
#if 0
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
    //���ַ�ʽ�������޳���
#endif
    //��Ϊ��֧�ֱ䳤���飬����ѡ�񴴿ռ䣬��
    int* arr = (int*)calloc(numsSize,sizeof(int));
    int* ret = (int*)calloc(2,sizeof(int));
    //�����൱��Ͱ��
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
//С��ͬѧ���������һ����վ�����û�ע���˻���ʱ����Ҫ�����˻������룬Ϊ�˼�ǿ�˻��İ�ȫ�ԣ�С��������ǿ����һ��Ҫ��
//1. ����ֻ���ɴ�д��ĸ��Сд��ĸ�����ֹ��ɣ�
//2. ���벻�������ֿ�ͷ��
//3. ���������ٳ��ִ�д��ĸ��Сд��ĸ�������������ַ������е����֣�
//4. ���볤������Ϊ8
//����С���ܵ���n�����룬��������д�����ж���Щ��������Щ�Ǻ��ʵģ���Щ�ǲ��Ϸ��ġ�
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
//����һ������Ϊ n �ķǽ��������һ���Ǹ������� k ��Ҫ��ͳ�� k �������г��ֵĴ���
//Ҫ�󣺿ռ临�Ӷ�
//O(1)��ʱ�临��O(logn)
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
    }//����ͬ�����Ҷ�
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
    }//��ͬ�������
    int tagleft = right + 1;
    return tagright - tagleft + 1;
}
//����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B��
//λ������
int convertInteger(int A, int B) 
{
#if 0
    int ret = 0;
    //�������������Ȼ��һλλȡ�����е�1
    int xor = A ^ B;
    while (xor)
    {
        if (xor &1)//��1���Ϊ1˵��������1��˵��A��B����һλ��ͬ
            ret++;
        xor >>= 1;
    }
    return ret;
#endif
    //������������������룬����һ�����͵Ĵ�����룬���Ľ������ѭ����ԭ�������Ʋ�������Ϊ�����������㣬��������ʱ���÷���λ���ģ����߼���������0���ģ�ojʱ�������1������ѭ��������������ͳһ��0
    //�޸�ʱ����Ҫ�޶�λ��
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
//����һ���������� nums ���������Ǵ��� Ψһ�� һ��������� ��
//�����ҳ������е����Ԫ�ز�������Ƿ� ������������ÿ���������ֵ����� ������ǣ��򷵻� ���Ԫ�ص��±� �����򷵻� - 1 ��
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
//������������ nums1 �� nums2 ������ ���ǵĽ��� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳�� ��
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
//Lily�Ͽ�ʱʹ����ĸ����ͼƬ��С������ѧϰӢ�ﵥ�ʣ�ÿ�ζ���Ҫ����ЩͼƬ���մ�С��ASCII��ֵ��С���������պá����Ҹ�Lily��æ��ͨ����������
//Lilyʹ�õ�ͼƬʹ���ַ�"A"��"Z"��"a"��"z"��"0"��"9"��ʾ��
int charcmp (const void* p1, const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}
void sort_ASCLL(char* str)
{
    //�������Ǹ�ϰһ��qsort��ð��
  //qsort
#if 1
    int len = strlen(str);
    qsort(str,len,sizeof(char),charcmp);
#endif
    //ð��
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
//����һ���������� nums ������������ �����±� ��
//���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ��
//�������Ҷ�ͬ������
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