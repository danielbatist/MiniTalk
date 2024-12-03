/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:13 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 14:58:58 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putnbr_hex_up(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_putnbr_hex_up(nb / 16);
	count += ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (count);
}
