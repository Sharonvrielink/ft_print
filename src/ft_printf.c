/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:03:04 by svrielin      #+#    #+#                 */
/*   Updated: 2021/11/24 19:03:01 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

/* 
1.  Print format string until you find a %
2.  BONUS Parse the flags that come after, and put the result in some struct
3.  Find the conversion type (i, c, s, ect), 
    pass the created struct to a function (print_c(t_struct *flags) 
    and interpret the struct again inside that funcion 
    (precision means something different for i than s)
4.  Convert the whole conversion to a string, print that
5.  Repeat
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (!format)
		return (0);
	va_start (args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		//go to conversion
		i++;
	}
	return(1);
	va_end (args);
}
