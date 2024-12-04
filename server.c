/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:40:39 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/04 10:48:38 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

typedef struct s_server
{
	unsigned char	c;
	int				bit;
} t_server;

t_server	g_server = {0, 0};
void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		g_server.c |= (1 << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 8)
	{
		write(1, &g_server.c, 1);
		if (g_server.c == '\0')
			write(1, "\n", 1);
		g_server.c = 0;
		g_server.bit = 0;
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
