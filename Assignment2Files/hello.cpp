//找出一个字符串中第一个重复出现的字符  
//超级牛逼的方法  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>//memset  
#include <memory.h>  
#include <iostream>  
#define N 256  






char Find(char str[], int n)
{
	char temp[N] = { 0 };
	char dst;
	//memset((void *)temp,0x00,N*sizeof(char));  

	for (int i = 0; i < n; ++i)
	{
		int num = (int)str[i];
		if (temp[num] == 0)
		{
			temp[num] = num;
		}
		else
		{
			dst = temp[num];
			//std::cout << dst ;  
			break;
		}
	}
	return dst;
}

int main()
{
	char s[] = "abcdefefddaddf";
	//char ch;  
	char a = Find(s, sizeof(s) / sizeof(char));
	std::cout << a;
}