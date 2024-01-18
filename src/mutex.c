/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:58:10 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/18 16:31:08 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

/*
概要: この関数はt_tools型のポインターを引数として受け取り、プログラムの終了状態をチェックします。
pthread_mutex_lockを使用してtoolsのステータスにアクセスし、tools->endの値に基づいて終了状態を判断します。
*/
int	check_end(t_tools *tools)
{
	int	status;

	pthread_mutex_lock(&tools->lock);
	if (tools->end)
		status = 1;
	else
		status = 0;
	pthread_mutex_unlock(&tools->lock);
	return (status);
}

/*
    宣言: void change_end(t_tools *tools)
    概要: この関数もt_tools型のポインターを引数として受け取り、プログラムの終了状態を変更します。
	ミューテックスを使用してステータスをロックし、tools->endをtrueに設定します。
*/
void	change_end(t_tools *tools)
{
	pthread_mutex_lock(&tools->lock);
	tools->end = true;
	pthread_mutex_unlock(&tools->lock);
}

void	set_m_t(t_philo *philo)
{
	pthread_mutex_lock(&philo->tools->eat);
	philo->time_last_meal = get_ms();
	pthread_mutex_unlock(&philo->tools->eat);
}


long	read_m_t(t_philo *philo)
{
	long	last_meal_time;
	pthread_mutex_lock(&philo->tools->eat);
	last_meal_time = philo->time_last_meal;
	pthread_mutex_unlock(&philo->tools->eat);

	return (last_meal_time);
}