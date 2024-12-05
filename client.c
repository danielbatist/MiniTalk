/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:11:26 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/05 19:20:01 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

void	send_bits(int pid, char *str, size_t len)
{
	size_t	i;
	int		s;

	i = 0;
	while (i <= len)
	{
		s = 0;
		while (s < 8)
		{
			if ((str[i] >> s) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			s++;
			usleep(1000);
		}
		usleep(500);
		i++;
	}
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		write(1, "The message was received successfully.\n", 37);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int		pid;

	if (argc == 3)
	{
		sa.sa_handler = handle_ack;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Error, Invalid PID.\nPlease, Try again.\n");
			return (1);
		}
		send_bits(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_printf("Error!\nUsable: %s <PID> <argument>\n", argv[0]);
	return (0);
}
