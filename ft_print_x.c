/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:41:03 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/20 14:49:15 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_0xdigit (unsigned int n)
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

static	int	ft_print_x (unsigned int n, char format)
{
	char	c;

	if (num >= 16)
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
}

