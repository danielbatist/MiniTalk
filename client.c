/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbatista <dbatista@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:11:26 by dbatista          #+#    #+#             */
/*   Updated: 2024/12/03 18:21:13 by dbatista         ###   ########.fr       */
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
		while (s < 7)
		{
			if ((str[i] >> s) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			s++;
		}
		usleep(300);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]); // Tratar pid que tenha numeros junto com qualquer outra caracter.
		if (pid <= 0)
		{
			ft_printf("Error, Invalid PID.\n");
			ft_printf("Please, Try again.\n");
			return (1);
		}
		str = argv[2];
		send_bits(pid, str, ft_strlen(str));
	}
	else
	{
		ft_printf("Error!\n Usable: %s <PID> <argument>\n", argv[0]);
	}
	return (0);
}
