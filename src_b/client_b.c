/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:17:30 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/29 22:04:56 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("Message Recieved!\n", 1);
}

void	send_signal(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Problem sending the signal!\n", 1);
			exit(1);
		}
		usleep(250);
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Problem sending the signal!\n", 1);
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
	signal(SIGUSR1, ft_handler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 1)
			return (ft_putstr_fd("INVALID PID\n", 1), 0);
		while (av[2][i])
			ft_convert(av[2][i++], pid);
		ft_convert('\0', pid);
	}
	else
		ft_putstr_fd("INVALID ARGUMENTS!\nUsage: ./client [PID] [STRING]\n", 1);
	return (0);
}
