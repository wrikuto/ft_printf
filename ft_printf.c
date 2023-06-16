/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:39:32 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/16 17:43:05 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"



int	ft_identify(va_list	args, const char format)
{
	int	n;

	if (format == 'c')
		return (ft_printchar_fd(va_arg(args, int)));
	if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_printvoidtype((uintptr_t)va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_printnum(va_arg(args, int)));
	if (format == 'u')
		return (ft_printnbr_fd(va_arg(args, unsigned int), 1));
	if (format == 'x' || format == 'X')
		hogehoge(va_arg(args, unsigned int));
	if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	size_t		i;
	size_t		len;
	va_list		args;

	i = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (*input == '%')
			len = len + ft_identify(args, *input);
		else
			write(1, &input[i], 1);
		i++;
		len++;
	}
	return (0);
}
