/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printhex_upper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:51:11 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 16:51:14 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	printhex_upper(va_list args, int *len)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(args, unsigned int);
	str = ft_itoa_base(nbr, 16);
	str = ft_strtoupper(str);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(nbr, 16);
}
