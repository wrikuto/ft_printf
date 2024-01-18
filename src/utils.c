/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:56:55 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/17 18:15:04 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

// toolsに格納されている各哲学者のスレッドを終了（ジョイン）します。
int	join_threads(t_tools *tools)
{
	int	i;

	i = 0;
	while (i < tools->num_philo)
	{
		// pthread_join(tools->philo[i].thread, NULL): 各哲学者のスレッドに対してpthread_joinを呼び出し、
		// スレッドの終了を待ちます。失敗した場合は1を返します。
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

// スレッドセーフな方法で哲学者の状態を出力します。
void	print_philo_status(char *str, int id, t_tools *tools, long ms)
{
	// 出力前にミューテックスをロックします。
	pthread_mutex_lock(&(tools->lock));
	// プログラムが終了していない場合、哲学者の状態を出力します。
	if (!tools->end)
		printf("%ld Philosopher %i %s\n", ms, id, str);
	// 出力後にミューテックスをアンロックします。
	pthread_mutex_unlock(&(tools->lock));
}
