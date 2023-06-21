/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:38:14 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/21 22:13:15 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_digit_p(uintptr_t n)
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

static	void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else
			ft_print_c((n - 10) + 'a');
	}
}

int	ft_print_p(uintptr_t n)
{
	write(1, "0x", 2);
	if (n == 0)
		return (write(1, "0", 1) + 2);
	ft_put_ptr(n);
	return (ft_digit_p(n) + 2);
}

// int main()
// {
//     int i;

// 	i = 1;
//     ft_print_p((uintptr_t)(&i - 1));
//     write(1, "\n", 1);
//     return 0;
// }
