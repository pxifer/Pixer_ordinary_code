#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<windows.h>
#include"imitation.h"

int main()
{
	char arr1[50] = "llbitll";
	char arr2[] = "bit";
	//char* a=my_strcpy(arr1,arr2);//
	//char* b=my_strcat(arr1, arr2);//
	//int c=my_strlen(arr1);
	//int d=my_strcmp(arr1,arr2);
	/*char* e = my_strstr(arr1, arr2);
	printf("%s\n", e);*/
	//void*f=my_memcpy(arr1,arr2,sizeof(arr2));
	void* h=my_memmove(arr1, arr1 + 2,12);
}

char* my_strcpy(char* dest, const char* res)
{
	assert(dest && res);
	char* ret = dest;
	while (*dest++ = *res++);
	return ret;
}

char* my_strcat(char* dest, const char* res)
{
	assert(dest && res);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	/*while (*dest++);//第二种写法；
	dest--;*/
	while (*dest++ = *res++);
	return ret;
}
int my_strlen(const char* arr1)
{//三种实现方法；
	assert(arr1);
	/*int count = 0;//方法1：计数器法；
	while ((*arr1)++)
		count++;
	return count;*/

	/*if (!*arr1)//方法2：递归法；
		return 0;
	else
		return 1 + my_strlen(arr1 + 1);*/

	/*char* p = arr1;//方法3：指针差减法；
	while (*p)
		p++;
	return p - arr1;*/
}

int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while(*arr1 == *arr2)
	{
		if (*arr1 == '\0')
			return 0;
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
	/*if (*arr1 > *arr2)//VS编译器；
		return 1;
	else
		return -1;*/
}

char* my_strstr(const char* p1, const char* p2)//还有优化算法（微信）
{
	assert(p1 && p2);
	char* s1, *s2;
	char* cur = (char*)p1;
	if (!*p2)
		return (char*)p1;

	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while(*s1&&*s2&&!(*s1-*s2))
		s1++,s2++;

		if (!*s2)
			return cur;
		if (!*s1)
			return NULL;
		cur++;
	}
}

void* my_memcpy(void* arr1, const void* arr2, size_t num)
{
	assert(arr1 && arr2);
	void* ret = arr1;
	while (num--)
	{
		*(char*)arr1 = *(char*)arr2;
		++(char*)arr1;
		++(char*)arr2;
	}
	return ret;
}

void* my_memmove(void* dst, const void* src, size_t num)
{
	assert(dst && src);
	void* ret = dst;
	if (dst > src)
	{
		while (num--)
		{
			*((char*)dst + num ) = *((char*)src + num );
		}
	}
	else
	{
		while (num--)
		{
			*(char*)dst = *(char*)src;
			++(char*)dst;
			++(char*)src;
		}
	}
	return ret;
}