/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:39:32 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/20 20:52:09 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	int	ft_identify(va_list	args, const char format)
{
	int	n;

	if (format == 'c')
		return (ft_print_c(va_arg(args, char)));
	if (format == 's')
		return (ft_print_s(va_arg(args, char *)));
	if (format == 'p')
		return (ft_print_p((uintptr_t)va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_print_d(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_print_x(va_arg(args, unsigned int), format));
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
	len = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
			len = len + ft_identify(args, input[i + 1]);
		else
			len++;
		i++;
	}
	va_end(args);
	return (len);
}
