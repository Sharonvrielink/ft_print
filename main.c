#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	int		return_printf;
	char	*str;	

	str = "Hallo hallo\n";
	ft_putstr_fd(str, 1);
	return_printf = printf("Str = %s\n", str);
	printf("Return_printf = %d\n", return_printf);
}
