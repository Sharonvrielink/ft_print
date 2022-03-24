/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:03:04 by svrielin      #+#    #+#                 */
/*   Updated: 2022/03/22 14:38:15 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

void printchar(int arg, int *len)
{
	ft_putchar_fd(arg, 1);
	*len += 1;
}

void printstring(char *str, int *len)
{
	if(str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*len = *len + ft_strlen(str);
}

void printnumber(int arg, int *len)
{
	ft_putnbr_fd(arg, 1);
	*len += ft_numlen(arg);
}

void printunsignednumber(unsigned int arg, int *len)
{
	char *str;
	str = ft_itoa_base(arg, 10);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(arg, 10);
}

void printhex(unsigned int arg, int *len)
{
	char *str;
	str = ft_itoa_base(arg, 16);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(arg, 16);
}

void printhex_upper(unsigned int arg, int *len)
{
	char *str;
	str = ft_itoa_base(arg, 16);
	str = ft_strtoupper(str);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(arg, 16);
}

void printpointer(unsigned long long arg, int *len)
{
	char *str;
	
	ft_putstr_fd("0x", 1);
	str = ft_itoa_base(arg, 16);
	ft_putstr_fd(str, 1);
	free(str);
	*len = 2 + (*len + ft_numlen_base(arg, 16));
}

void preconverter(char specifier, va_list args, int *len)
{
	if (specifier == 'c')
		printchar(va_arg (args, int), len);
	if (specifier == 's')
		printstring(va_arg (args, char*), len);
	if (specifier == 'd' || specifier == 'i')
		printnumber(va_arg (args, int), len);
	if (specifier == 'u')
		printunsignednumber(va_arg (args, unsigned int), len);
	if (specifier == 'x')
		printhex(va_arg (args, int), len);
	if (specifier == 'X')
		printhex_upper(va_arg (args, int), len);
	if (specifier == 'p')
		printpointer((unsigned long)va_arg(args, void *), len);
	if (specifier == '%')
		printchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start (args, format);
	while (format[i] != '\0')
	{		
		if (format[i] == '%' && format[i + 1])
		{
			preconverter(format[i + 1], args, &len);
			i += 2;
		}
		else 
		{
			ft_putchar_fd(format[i], 1);
			len++;
			i++;
		}
	}
	return(len);
	va_end (args);
}
