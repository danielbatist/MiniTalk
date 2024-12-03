/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:54:56 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 14:55:27 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putptr(unsigned long nbr, int pre)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		return (ft_putstr("(nil)"));
	}
	if (pre == 0)
		count += ft_putstr("0x");
	if (nbr > 15)
		count += ft_putptr((nbr / 16), 1);
	count += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}

