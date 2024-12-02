/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:40:39 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/02 15:52:00 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle_sigusr1(int signum)
{
	(void)signum;
	write(1, "SIGUSR1 recebido\n", 17);
}

void	handle_sigusr2(int signum)
{
	(void)signum;
	write(1, "SIGUSR2 recebido", 17);
}

int	main(void)
{
	printf("Servidor iniciado. PID: %d\n", getpid());
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while (1)
	{
		pause();
	}
	return (0);
}
