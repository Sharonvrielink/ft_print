/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstring.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:30:46 by svrielin      #+#    #+#                 */
/*   Updated: 2022/04/22 15:52:58 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	printstring(va_list args, int *len)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*len = *len + ft_strlen(str);
}
