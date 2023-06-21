/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:20:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/21 22:40:29 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *input)
{
	size_t	i;

	i = 0;
	if (!input)
		return (write(1, "(null)", 6));
	while (input[i] != '\0')
	{
		write(1, &input[i], 1);
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
