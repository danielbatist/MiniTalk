/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:40:39 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/04 19:38:35 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

typedef	struct s_server
{
	unsigned char	c;
	int	bit;
} 	t_server;

t_server	g_server;

void	treat_signal(int sig)
{
	

	if (sig == SIGUSR2)
		g_server.c |= (1 << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 8)
	{
		write(1, &g_server.c, 1);
		if (g_server.c == '\0')
		{
			write(1, "\n", 1);
			//kill(pid, SIGUSR1);
		}
		g_server.c = 0;
		g_server.bit = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to dbatista server!!!\n");
	ft_printf("PID: %d\n", getpid());
	
	signal(SIGUSR1, treat_signal);
	signal(SIGUSR2, treat_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
