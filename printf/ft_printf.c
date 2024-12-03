/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:23:13 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 15:04:48 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selector(const char *format, va_list args)
{
	int		c;

	c = 0;
	if (*format == '%')
		c += ft_putchar('%');
	else if (*format == 'c')
		c += ft_putchar((char)va_arg(args, int));
	else if (*format == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		c += ft_putptr(va_arg(args, unsigned long), 0);
	else if (*format == 'd' || *format == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		c += ft_putnbr_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		c += ft_putnbr_hex_low(va_arg(args, unsigned int));
	else if (*format == 'X')
		c += ft_putnbr_hex_up(va_arg(args, unsigned int));
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start (args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_selector(&format[i], args);
		}
		else
		{
			write (1, &format[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return (count);
}
