#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int		retft_printf;
	int		retprintf;
	int		i;
	int		len;
	
	i = -1;

	printf("Test ? = ft_printf\nTest ! = printf\n\n");

	printf("Test 1\n");
	retft_printf = ft_printf(" %d ", 30);
	printf("|\n--------------------------------------\n");
	retprintf = printf(" %d ", 30);
	printf("|\nReturn ft_printf = %d\nReturn printf = %d\n", retft_printf, retprintf);

	printf("I=%i | U=%u\n", -1, (unsigned)-1);
	ft_printf("I=%i | U=%u\n", -1, (unsigned)-1);
	len = ft_numlen(i);
	printf("Numlen -1 = %d\n", len);
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
