/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:58:47 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/17 12:50:12 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include"libft/libft.h"
#include<stdarg.h>

int	ft_printchar_fd(char c);
int	ft_printstr(char *input);
int	ft_printvoidtype(char *input);
int	ft_printnbr(unsigned int n);



#endif
