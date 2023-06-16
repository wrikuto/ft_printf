/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:16 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/16 18:21:03 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_numdigit(unsigned int n)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	int	ft_power(int base, int exp)
{
	int	i;
	int	result;

	result = 1;
	if (base == 0 && exp < 0)
		return (0);
	else
	{
		i = 0;
		while (i < exp)
		{
			result *= base;
			i++;
		}
	}
	return (result);
}

int	ft_printnbr_fd(unsigned int n, int fd)
{
	int		nb;
	int		i;
	int		res;

	res = 0;
	i = ft_numdigit(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		while (i > 0)
		{
			nb = (n / ft_power(10, i - 1));
			ft_putchar_fd((nb / ft_power(10, i - 1)) + '0', fd);
			nb = nb % ft_power(10, i - 1);
			i--;
			res++;
		}
	}
	return (res);
}
