/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:28:58 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 16:54:51 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	printchar(va_list args, int *len);
void	printstring(va_list args, int *len);
void	printnumber(va_list args, int *len);
void	printunsignednumber(va_list args, int *len);
void	printhex(va_list args, int *len);
void	printhex_upper(va_list args, int *len);
void	printpointer(va_list args, int *len);

#endif
