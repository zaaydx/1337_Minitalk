/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:55:16 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/29 23:55:33 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	translate_message(int sig)
{
	static int	n;
	static int	bit;

	if (sig == SIGUSR1)
		bit += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_putchar(bit);
		n = 0;
		bit = 0;
	}
}

int	main(int argc, char	**argv)
{
	pid_t	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr("PID : ");
		ft_putnbr(pid);
		ft_putchar('\n');
		signal(SIGUSR1, translate_message);
		signal(SIGUSR2, translate_message);
		while (1)
			pause();
	}
	return (0);
}
