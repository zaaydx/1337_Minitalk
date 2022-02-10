/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:55:46 by zchbani           #+#    #+#             */
/*   Updated: 2021/12/29 23:56:03 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_check(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *ptr)
{
	int	i;
	int	n;
	int	sign;
	int	k;

	n = 0;
	k = 0;
	sign = 1;
	i = ft_check(ptr);
	while (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -sign;
		k++;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		n = n * 10 + (ptr[i] - 48);
		i++;
	}
	if (k > 1)
		return (0);
	return (n * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char	z;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		z = n + '0';
		ft_putchar(z);
	}
	else
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
}
