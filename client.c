/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:11:26 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/02 18:36:23 by dbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		printf("Unable to continue!\n");
		printf("Example: %s 12345 \n", argv[0]);
		return (1);
	}
	pid = atoi(argv[1]); // Tratar pid que tenha numeros junto com qualquer outra caracter.
	if (pid <= 0)
	{
		printf("Error, Invalid PID.\n");
		printf("Please, Try again.\n");
		return (1);
	}
	printf("Enviando SIGUSR1 para o PID %d\n", pid);
	kill(pid, SIGUSR1);
	usleep(300000);

	printf("Enviando SIGUSR2 para o PID %d\n", pid);
	kill(pid, SIGUSR2);
	usleep(300000);
	return (0);
}
