/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:54:14 by wrikuto           #+#    #+#             */
/*   Updated: 2024/01/15 17:42:29 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

// 機能: 現在の時刻をミリ秒単位で取得します。
long	get_ms(void)
{
	struct timeval	current_time; // 現在時刻を格納するためのtimeval構造体を宣言します。

	
	gettimeofday(&current_time, NULL); // gettimeofday関数を使って現在の時刻を取得します。
	// 秒単位の時刻をミリ秒に変換し、マイクロ秒単位の時刻もミリ秒に変換して合計します。
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}


// 機能: この関数は引数としてstart（開始時刻）を受け取り、現在時刻との差（経過時間）をミリ秒単位で返します。
long	elapsed_time(long start)
{
	// 動作: get_ms()関数を呼び出して現在時刻をミリ秒単位で取得し、引数startから差し引いて経過時間を計算します。
	return (get_ms() - start);
}
