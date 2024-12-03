/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:55:48 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 14:56:09 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putnbr_hex_low(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_putnbr_hex_low(nb / 16);
	count += ft_putchar("0123456789abcdef"[nb % 16]);
	return (count);
}
