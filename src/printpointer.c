/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printpointer.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:51:55 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 16:52:02 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	printpointer(va_list args, int *len)
{
	char			*str;
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	ft_putstr_fd("0x", 1);
	str = ft_itoa_base(p, 16);
	ft_putstr_fd(str, 1);
	free(str);
	*len = 2 + (*len + ft_numlen_base(p, 16));
}
