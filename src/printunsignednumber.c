/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printunsignednumber.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:34:48 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/24 14:11:31 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	printunsignednumber(va_list args, int *len)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(args, unsigned int);
	str = ft_ulltoa_base(nbr, 10);
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_unsignednumlen_base(nbr, 10);
}
