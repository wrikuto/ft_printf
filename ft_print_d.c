/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:14:23 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/22 14:20:49 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_numdigit(int n)
{
	int	num;
	int	i;

	i = 0;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	int	ft_power(unsigned int base, unsigned int exp)
{
	unsigned int	i;
	unsigned int	result;

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

int	ft_print_d(int n)
{
	int			i;
	long int	lng;
	int			res;
	char		c;

	lng = n;
	i = ft_numdigit(n);
	res = i;
	if (lng < 0)
	{
		write(1, "-", 1);
		lng = -lng;
		res++;
	}
	if (lng == 0)
		return (write(1, "0", 1));
	while (i > 0)
	{
		c = (lng / ft_power(10, i - 1)) + '0';
		write(1, &c, 1);
		lng = lng % ft_power(10, i - 1);
		i--;
	}
	return (res);
}

// #include<stdio.h>

// int main() {
//     int num = 23423245;
//     int printed = ft_printnbr(num);
//     printf("\nNumber of digits printed: %d\n", printed);
//     return 0;
// }
