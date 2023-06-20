/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:41:03 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/20 21:33:00 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_0xdigit(unsigned int n)
{
	int		dig;

	dig = 0;
	while (n != 0)
	{
		n = n / 16;
		dig++;
	}
	return (dig);
}

int	ft_print_x(unsigned int n, char format)
{
	int		dig;

	dig = ft_0xdigit(n);
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		ft_print_x(n / 16, format);
		ft_print_x(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else
		{
			if (format == 'x')
				ft_print_c((n - 10) + 'a');
			if (format == 'X')
				ft_print_c((n - 10) + 'A');
		}
	}
	return (dig);
}


// #include<stdio.h>

// int main(void)
// {
// 	int i;
// 	unsigned int num1 = 12345;
// 	unsigned int num2 = 0;
// 	unsigned int num3 = 254;
// 	char format1 = 'x';
// 	char format2 = 'X';

// 	i = ft_print_x(num1, format1);
// 	printf("\nexpect: 4, return dig is %d\n", i);
// 	ft_print_x(num1, format2);
// 	write(1, "\n", 1);

// 	ft_print_x(num2, format1);
// 	write(1, "\n", 1);
// 	ft_print_x(num2, format2);
// 	write(1, "\n", 1);

// 	ft_print_x(num3, format1);
// 	write(1, "\n", 1);
// 	ft_print_x(num3, format2);
// 	write(1, "\n", 1);
// 	i = ft_print_x(num3, format1);
// 	return (0);
// }