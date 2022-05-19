#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char str1[15];
	char str2[15];
	int ret;

	ft_memcpy(str1, "abcdef", 6);
	ft_memcpy(str2, "ABCDEF", 6);

	ret = ft_memcmp(str1, str2, 5);

	if(ret > 0) 
	{
		printf("str2 is less than str1");
	}
	else if(ret < 0)
	{
		printf("str1 is less than str2");
	}
   else
	{
		printf("str1 is equal to str2");
	}

	// int i;

	// i = 0;

	// printf("i = %X\n", i);
	// ft_printf("i = %X\n", i);


	// int		retft_printf;
	// int		retprintf;
	// char	*p; 
	
	// p = "hello";

	// printf("Test 1\n");
	// retft_printf = ft_printf(" %p ", p);
	// printf("|\n--------------------------------------\n");
	// retprintf = printf(" %p ", p);
	// printf("|\nReturn ft_printf = %d\nReturn printf = %d\n", retft_printf, retprintf);
	return(0);
}
/*int	main(void)
{
	int		return_printf;
	int		return_ft_printf;
	char *	str;	

	return_printf = printf("Test0 only a string\n");
	printf("Return_printf = %d\n", return_printf);
	return_ft_printf = ft_printf("Test0 only a string\n");

	char c;
    char c0;
    char c1;
    int i;

    c = 'C';
    c0 = 'S';
    c1 = 'J';
    i = -50000;
    //ft_printf("Test1 string with char %%c: %c that will continue after parsing\n", c);
    //ft_printf("Test2 string with char 1: %c and char 2: %c\n", c0, c1);
    //ft_printf("Test3 string with decimal format specifier %%d: %d\n", i);
    //ft_printf("Test4 string with int %%i: %i and char %%c: %c\n", i, c);
    //ft_printf("Test5 string with char as %%i: %i and int as %%c: %c\n", c, i);
    //printf("Printf for test5 string with char as %%i: %i and int as %%c: %c\n", c, i);
}*/
