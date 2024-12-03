/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:40:39 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 19:13:53 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

void	handle_signal(int sig)
{
	unsigned char c;
	int	bit;

	c = 0;
	bit = 0;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (sig == 8)
	{
		write(1, &c, 1);
		if (sig == '\0')
			write(1, "\n", 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to dbatista server!!!\n");
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
