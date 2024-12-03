/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:40:39 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/02 23:56:13 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_msg
{
	unsigned char	c;
	int				bit_index;
}				t_msg;

t_msg	g_msg;

g_msg = {0, 0};

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		g_msg.c |= (1 << g_msg.bit_index);
	g_msg.bit_index++;
	if (sig == 8)
	{
		write(1, &g_msg.c, 1);
		if (sig == '\0')
			write(1, "\n", 1);
		g_msg.c = 0;
		g_msg.bit_index = 0;
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
