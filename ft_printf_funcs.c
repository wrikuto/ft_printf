/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:20:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/17 21:21:46 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_str(char *input)
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

int	ft_print_voidtype(char *input)
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
