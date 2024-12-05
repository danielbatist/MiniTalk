/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:40:39 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/05 19:33:04 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

void	treat_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		bit = 0;
	}
}

#include <stdio.h>
int	main(void)
{
	struct sigaction	sa;

 		 printf("     _______. _______ .______     ____    ____  _______ .______\n");
 	    printf("    /       ||   ____||   _  \\    \\   \\  /   / |   ____||   _  \\\n");
 	   printf("   |   (----`|  |__   |  |_)  |    \\   \\/   /  |  |__   |  |_)  |\n");
 	    printf("    \\   \\    |   __|  |      /      \\      /   |   __|  |      /\n");
 	printf(".----)   |   |  |____ |  |\\  \\----.  \\    /    |  |____ |  |\\  \\----.\n");
 	printf("|_______/    |_______|| _| `._____|   \\__/     |_______|| _| `._____|\n");
 	printf("\nServer is running... 🚀\n");
	ft_printf("Welcome to dbatista server!!!\n");
	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = treat_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
