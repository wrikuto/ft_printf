/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:20:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/16 17:06:27 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printstr(char *input)
{
	size_t	i;

	while (input[i] != '\0')
	{
		write(1, &input, 1);
		i++;
	}
	return (i);
}

int	ft_printvoidtype(char *input)
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

int	ft_printnum(int input)
{
	int		len;
	char	*print;

	len = 0;
	print = ft_itoa(input);
	len = ft_printstr(print);
	free(print);
	return (len);
}



// int ft_put