/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:28:04 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 18:15:37 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long nbr, int pre);
int		ft_putnbr(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr_hex_low(unsigned int nb);
int		ft_putnbr_hex_up(unsigned int nb);
int		ft_printf(const char *format, ...);

#endif