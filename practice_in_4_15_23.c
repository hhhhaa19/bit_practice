#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//?????????
/*
void plant(int x, int y, int a)
{
    char arr[12] = { '1' };
    int i;
    arr[x - 1] =  '*' ;
    arr[y - 1] =  '*' ;
    for (i = 0; i++; i >=a)
        printf("%c/n", arr[i]);
}
int main()
{
    plant(6, 7, 12);
    plant(6, 7, 12);
    plant(1, 12, 12);
    return 0;
}
*/
// 取余对应%
/*int main() {
    int a;
    scanf("%d", &a);
    if (a % 5 == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}*/
/*10进制转60*/
// 整除与取余
/*
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d", a / b, a % b);
    return 0;
}
*/
/*
int main() {
    int a;
    scanf("%d", &a);
    printf("%d %d %d", a / (60 * 60), (a - (a / (60 * 60)) * (60 * 60)) / 60, a % 60);
    return 0;
}
*/
//11
/*
int main() {
int a=40;
int c=212;
printf("%d",a*(-8+22)-10+c/2);
    return 0;
}*/
/*
int compare (int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int main()
{
   printf("%d", compare(2, 3));
    return 0;
}
*/
//int main() {
//    long x;
//    scanf("%ld", &x);
//    printf("%d", (x / 12) * 4 + 2);
//    return 0;
//}
//注意调用的顺序，以及printf的返回值是打印的字符数
/*
int main() {
    printf("\n%d\n", printf("Hello world!"));
    return 0;
}
*/
//judge triangle, and keep input till the iuput is 3 elements
//int main() {
//    int a, b, c;
//    while (scanf("%d %d %d", &a, &b, &c) == 3)//!!!!!!!important, notice the sequence
//    {
//        if (a + b > c && b + c > a && a + c > b)
//        {
//            if (a == b || b == c || c == a)
//            {
//                if (a == b && b == c && c == a)
//                {
//                    printf("Equilateral triangle!\n");
//                }
//                else
//                {
//                    printf("Isosceles triangle!\n");
//                }
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//the characteristic of long long int 
/*
int main() {
int a;
long long x;
scanf("%d",&a);
x=a*31560000;
printf("%lld",x);
    return 0;
}*/