/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:58:47 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/20 21:36:42 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdint.h>

int		ft_print_c(char c);
int		ft_print_s(char *input);
int		ft_print_p(char *input);
int		ft_print_d(int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int n, char format);

#endif



