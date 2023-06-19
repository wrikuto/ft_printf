/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:20:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/20 02:41:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_print_c(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

int	ft_print_s(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] != '\0')
	{
		write(1, &input, 1);
		i++;
	}
	return (i);
}

int	ft_print_p(char *input)
{
	size_t	i;

	i = 0;
	if (input == NULL)
		return (write(1, "null", 4));
	while (input[i] != '\0')
	{
		write(1, &input, 1);
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int main()
// {
// 	int i = 1;
// 	int res;

// 	res = 0;
// 	res = ft_printnum(i);
// 	return (0);
// }
