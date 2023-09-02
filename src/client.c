/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:37 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/29 17:18:45 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_signal(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Problem sending the signal!\n", 29);
			exit(1);
		}
		usleep(250);
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Problem sending the signal!\n", 29);
			exit(1);
		}
		usleep(250);
	}
}

void	ft_convert(char c, int pid)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		send_signal(bit, pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 1)
		{
			ft_putstr_fd("INVALID PID\n", 1);
			return (0);
		}
		while (av[2][i])
		{
			ft_convert(av[2][i], pid);
			i++;
		}
	}
	else
		ft_putstr_fd("INVALID ARGUMENTS!\nUsage: ./client [PID] [STRING]\n", 1);
	return (0);
}
