/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printunsignednumber.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:34:48 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/12 16:34:52 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	printunsignednumber(va_list args, int *len)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(args, unsigned int);
	str = ft_itoa_base(nbr, 10);
	ft_putstr_fd(str, 1);
	free(str);
	*len += ft_numlen_base(nbr, 10);
}
