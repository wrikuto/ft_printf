/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:41:03 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/21 22:13:07 by wrikuto          ###   ########.fr       */
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
	return (ft_0xdigit(n));
}

// #include <limits.h>
// #include <stdio.h>
// int main()
// {
// 	printf("%x\n", -1);
// 	ft_print_x(-1, 'x');
// 	printf("\n");
// 	printf("%x\n", 0);
// 	ft_print_x(0, 'x');
// 	printf("\n");
// 	printf("%x\n", INT_MAX);
// 	ft_print_x(INT_MAX, 'x');
// 	printf("\n");

// 	printf("%x\n", INT_MIN);
// 	ft_print_x(INT_MIN, 'x');
// 	printf("\n");

// 	printf("%x\n", UINT_MAX);
// 	ft_print_x(UINT_MAX, 'x');
// 	printf("\n");

// }
