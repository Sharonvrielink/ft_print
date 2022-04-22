/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printnumber.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:31:54 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/22 15:52:49 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	printnumber(va_list args, int *len)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	*len += ft_numlen(nbr);
}
