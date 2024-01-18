/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:03:14 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/18 11:30:56 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

// 概要: この関数は整数の引数timeを取り、指定された時間だけスリープ（待機）します。
// 内部では、現在の時間を取得し、経過時間が指定された時間に達するまでループします。
void	ft_sleep(int time)
{
	long	start;
	long	elapsed;

	start = get_ms();
	elapsed = 0;
	while (elapsed < time)
	{
		usleep(time * 1000);
		elapsed = get_ms() - start;
	}
}

// 概要: t_philo型のポインターを引数として受け取り、哲学者の右側のフォークを決定します。
// 最初の哲学者の場合は特別な処理を行い、それ以外の場合は標準的な計算を行います。
int	get_right_fork(t_philo *philo)
{
	if (philo->id == 0)
		return (philo->tools->num_philo - 1);
	else
		return (philo->id - 1);
}

// 概要: t_philo型のポインターを引数として受け取り、哲学者が食事をする処理を行います。
// determine_r_fork関数を呼び出して右側のフォークを決定し、ミューテックスを使用してフォークをロックします。
int	eating(t_philo *philo)
{
	int	r_fork;

	r_fork = get_right_fork(philo);
	pthread_mutex_lock(&philo->tools->forks[r_fork]);
	print_philo_status("has picked up a fork", philo->id, philo->tools, \
				elapsed_time(philo->tools->start_time));
		
	pthread_mutex_lock(&philo->tools->forks[philo->id]);
	print_philo_status("has picked up a fork", philo->id, philo->tools, \
				elapsed_time(philo->tools->start_time));
		
	philo->time_last_meal = get_ms();

	philo->c_meals--;
	print_philo_status("is eating", philo->id, philo->tools,
		elapsed_time(philo->tools->start_time));

	ft_sleep(philo->tools->time_eat);

	pthread_mutex_unlock(&philo->tools->forks[r_fork]);
	pthread_mutex_unlock(&philo->tools->forks[philo->id]);
	return (1);
}

void	*philo_life(void *arg)
{
	t_philo			*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		usleep(philo->tools->time_eat * 1000);
	while ((check_end(philo->tools) != 1) && (philo->c_meals != 0))
	{
		print_philo_status("is thinking", philo->id, philo->tools, \
					elapsed_time(philo->tools->start_time));
		eating(philo);
		print_philo_status("is sleeping", philo->id, philo->tools, \
					elapsed_time(philo->tools->start_time));
		ft_sleep(philo->tools->time_sleep);
	}
	return (NULL);
}