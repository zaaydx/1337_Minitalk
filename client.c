/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:56:47 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/30 00:09:31 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

static void	ft_convert_char_to_sig(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error();
		}
		usleep(200);
		i--;
	}
}

static void	handler(char *pid_arg, char *message)
{
	int			pid;

	pid = ft_atoi(pid_arg);
	while (*message)
	{
		if (pid <= 0)
			error();
		ft_convert_char_to_sig(*message, pid);
		message++;
	}
	ft_convert_char_to_sig(*message, pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		error();
	pid = ft_atoi(argv[1]);
	handler(argv[1], argv[2]);
	return (0);
}
