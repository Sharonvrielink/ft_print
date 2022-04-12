/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:03:04 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 16:52:07 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

typedef void	(*t_fnptr)(va_list args, int *len);

void	converter(int specifier, va_list args, int *len)
{
	const static t_fnptr	dispatcher[255] = {
	['c'] = &printchar,
	['s'] = &printstring,
	['d'] = &printnumber,
	['i'] = &printnumber,
	['u'] = &printunsignednumber,
	['x'] = &printhex,
	['X'] = &printhex_upper,
	['p'] = &printpointer,
	};

	if (dispatcher[specifier] != NULL)
		return (dispatcher[specifier](args, len));
}

int	ft_printer(const char *format, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{		
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
			}
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
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (0);
	va_start (args, format);
	len = ft_printer(format, args);
	va_end (args);
	return (len);
}
