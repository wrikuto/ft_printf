/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:49:15 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/18 14:53:33 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
#include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

// typedef struct s_philo	t_philo;
// typedef struct s_data	t_data;


typedef struct s_philo
{
	int				id;
	pthread_t		thread; //哲学者に割り当てられたスレッド
	long			time_last_meal; // 最後に食事をした時刻。
	int				c_meals; // これまでに行った食事の回数。
	struct s_tools	*tools; //共有リソースへのポインタ。哲学者がアクセスするフォークやステータス管理に関するリソースを含む可能性があります。

}				t_philo;

typedef struct s_tools
{
	t_philo			*philo;
	pthread_mutex_t	*forks; // フォークのミューテックス配列。各フォークにはミューテックスが割り当てられ、哲学者がフォークを使用する際にロック／アンロックを行う
	pthread_mutex_t	lock; // ステータス情報のミューテックス。プログラムの状態を同期するために使用。
	// pthread_mutex_t	meal_time; // 食事時間の管理に使用されるミューテックス。
	bool			end;
	long			start_time;
	int				num_philo;
	int				time_dead;
	int				time_eat;
	int				time_sleep;
	int				eat_up;
}				t_tools;

// prepare
int	set_situation(char **arg, t_tools *tools);
int	prepare_dinner_party(t_tools *tools);

int		ft_atoi(const char *str);
void	*philo_life(void *tmp);

int		join_threads(t_tools *tools);
void	free_philo_and_forks(t_tools *tools);

int		is_philo_dead(t_tools *tools);
// void	track_philo_life(t_tools *tools);

int		check_end(t_tools *tools);
void	change_end(t_tools *tools);
void	set_m_t(t_philo *philo);
long	read_m_t(t_philo *philo);

// time.c
long	elapsed_time(long start);

// mutex
long	get_ms(void);

// utils
void	print_philo_status(char *str, int id, t_tools *tools, long ms);




#endif