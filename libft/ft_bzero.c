/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:00:55 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/03 17:37:25 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n--)
	{
		*p++ = 0;
	}
}

// #include <stdio.h>
// int main()
// {
// 	char str[4];
// 	char *s1;

// 	s1 = str;
// 	s1[0] = 'a';
// 	s1[1] = 'b';
// 	s1[2] = 'c';
// 	s1[3] = '\0';
// 	ft_bzero(s1, 1);
// 	printf("%s", s1);
// 	return (0);
// }
