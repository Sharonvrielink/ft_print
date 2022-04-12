/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:03:04 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 14:13:40 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

void printchar(va_list args, int *len)
{
	ft_putchar_fd(va_arg(args, int), 1);
	*len += 1;
}

void printstring(va_list args, int *len)
{
	char *str;

	str = va_arg(args, char *);
	if(str == NULL)
	 	str = "(null)";
	ft_putstr_fd(str, 1);
	*len = *len + ft_strlen(str);
}

void printnumber(va_list args, int *len)
{
	int nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	*len += ft_numlen(nbr);
}

void printunsignednumber(va_list args, int *len)
{
	unsigned int nbr;
	char *str;

	nbr = va_arg(args, unsigned int);
	str = ft_itoa_base(nbr, 10);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(nbr, 10);
}

void printhex(va_list args, int *len)
{
	unsigned int nbr;
	char *str;
	
	nbr = va_arg(args, unsigned int);
	str = ft_itoa_base(nbr, 16);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(nbr, 16);
}

void printhex_upper(va_list args, int *len)
{
	unsigned int nbr;
	char *str;
	
	nbr = va_arg(args, unsigned int);
	str = ft_itoa_base(nbr, 16);
	str = ft_strtoupper(str);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(nbr, 16);
}

void printpointer(va_list args, int *len)
{
	char *str;
	unsigned long p;
	
	p = (unsigned long)va_arg(args, void *);
	ft_putstr_fd("0x", 1);
	str = ft_itoa_base(p, 16);
	ft_putstr_fd(str, 1);
	free(str);
	*len = 2 + (*len + ft_numlen_base(p, 16));
}

typedef void (*t_fnptr)(va_list args, int *len);

void converter(int specifier, va_list args, int *len)
{
	const static t_fnptr preconverter[255] = {
		['c'] = &printchar,
		['s'] = &printstring,
		['d'] = &printnumber,
		['i'] = &printnumber,
		['u'] = &printunsignednumber,
		['x'] = &printhex,
		['X'] = &printhex_upper,
		['p'] = &printpointer,
	};
	
	if (preconverter[specifier] != NULL)
		return (preconverter[specifier](args, len));
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
			if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
			}
			else
				converter(format[i + 1], args, &len);
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
