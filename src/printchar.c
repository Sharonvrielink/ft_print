/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printchar.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:29:09 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 16:29:36 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	printchar(va_list args, int *len)
{
	ft_putchar_fd(va_arg(args, int), 1);
	*len += 1;
}
