/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:20:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/16 12:19:13 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(const char *input)
{
	size_t	i;

	while (input[i] != '\0')
	{
		write(1, &input, 1);
		i++;
	}
	return (i);
}

int	ft_putvoidtype(const char *input)
{
	size_t	i;

	if (input == NULL)
		return (write(1, "null", 4));
	while (input[i] != '\0')
	{
		write(1, &input, 1);
		i++;
	}
	return (i);
}



// int ft_put