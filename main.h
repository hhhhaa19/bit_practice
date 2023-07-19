#pragma once
#define col 5//总共五排
#define row 5//每排5个
#include <math.h>
#include <stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include <stdlib.h>
extern void tcon_time_converter(void);
extern void P_struct(void);
extern void Sum_factorial(void);
extern void Sum_factorial2(void);
extern void binary_search(void);
extern void mock_log(void);
extern void timeforsheet(int x);
extern void campare(void);
extern void cumloop(void);
extern void number9_in100(void);
extern void mutiple3(void);
extern void bubble_sort(int* arr, int sz);
extern void isprime100_200(void);
extern void exchange2(int* x, int* y);
extern int r_fib(int x);
extern int i_fib(int x);
extern int my_pow (int x, int n);
extern void  reverse_string(char* string);
extern void  reverse_string2(char* string);
extern size_t my_strlen(char* string);
extern size_t my_strlen2(char* string);
extern int factorial(int x);
extern void digital_pri(int x);
extern void exchange(char* x, char* y);
void ex_array(int* x, int* y, int n);
extern void re_array(int* arr, int n);
extern int ocuntbinary(int x);
extern int diffinbin(int x, int y);
extern void merge(void);
extern void printarr(int arr[], int  sz);
extern void re_str(char str[]);
extern int Narcissistic_num(int x);
extern void re_sentence2(void);
extern int is_increase(int(*arr)[col], int target);
extern char* le_string(char* pstr, int k);
extern char* my_strstr(char* str1, char* str2);
extern int my_strcmp(const char* str, const char* str2);
extern char* my_strcat(char* dest, const char* sou);
extern void* my_memcpy(void* des, const void* sou, size_t num); 
char* my_strncpy(char* destination, const char* source, size_t num);
char* my_strncat(char* destination, const char* source, size_t num);
int my_atoi(const char* str);