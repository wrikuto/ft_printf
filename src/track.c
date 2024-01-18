/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:02:33 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/18 16:36:28 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"


int	is_philo_dead(t_tools *tools)
{
	int		i;
	long	diff_meal;

	i = 0;
	while (i < tools->num_philo)
	{
		diff_meal = get_ms() - read_m_t(&tools->philo[i]);
		if (tools->time_dead < diff_meal)
		{
			change_end(tools);
			// toolsの終了状態を変更する関数を呼び出します。
			if (tools->philo[i].c_meals != 0)
			{
				printf("%ld Philosopher %d has died\n",
					elapsed_time(tools->start_time), tools->philo[i].id);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
