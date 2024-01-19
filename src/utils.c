/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:56:55 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/19 12:09:24 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	join_threads(t_tools *tools)
{
	int	i;

	i = 0;
	while (i < tools->num_philo)
	{
		if (pthread_join(tools->philo[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

void	free_philo_and_forks(t_tools *tools)
{
	free(tools->philo);
	free(tools->forks);
}

void	print_philo_status(char *str, int id, t_tools *tools, long ms)
{
	pthread_mutex_lock(&(tools->lock));
	if (!tools->end)
		printf("%ldms %i %s\n", ms, id, str);
	pthread_mutex_unlock(&(tools->lock));
}
