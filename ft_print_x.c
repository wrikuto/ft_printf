/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:41:03 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/20 15:24:28 by wrikuto          ###   ########.fr       */
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
	char	c;
	int		dig;

	dig = ft_0xdigit(n);
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		ft_print0x(n / 16, format);
		ft_print0x(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_printchar(n);
		else
		{
			if (format == 'x')
				ft_printchar((n - 10) + 'a');
			if (format == 'X')
				ft_printchar((n - 10) + 'A');
		}
	}
	return (dig);
}

