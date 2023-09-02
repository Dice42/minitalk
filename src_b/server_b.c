/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:17:41 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/29 17:16:20 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_byte	g_byte;

void	ft_set_bit(int bit, int *i, int pid)
{
	if (*i == 1)
		g_byte.bit_1 = bit;
	if (*i == 2)
		g_byte.bit_2 = bit;
	if (*i == 3)
		g_byte.bit_3 = bit;
	if (*i == 4)
		g_byte.bit_4 = bit;
	if (*i == 5)
		g_byte.bit_5 = bit;
	if (*i == 6)
		g_byte.bit_6 = bit;
	if (*i == 7)
		g_byte.bit_7 = bit;
	if (*i == 8)
	{
		g_byte.bit_8 = bit;
		write(1, &g_byte, 1);
		if (*(unsigned char *)&g_byte == '\0')
			kill(pid, SIGUSR1);
		*i = 0;
	}
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	int			client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (!i)
		i = 1;
	if (sig == SIGUSR1)
	{
		ft_set_bit(0, &i, client_pid);
		i++;
	}
	if (sig == SIGUSR2)
	{
		ft_set_bit(1, &i, client_pid);
		i++;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
