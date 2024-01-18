#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    pthread_mutex_t *lock;
    int thread_id;
    // 他の必要な変数をここに追加
} thread_data_t;

// スレッド関数
void* thread_function(void* arg)
{
    thread_data_t *data = (thread_data_t *)arg;

    pthread_mutex_lock(data->lock);
    printf("Thread %d is running\n", data->thread_id);
    pthread_mutex_unlock(data->lock);

    return NULL;
}


int main()
{
	int i = 0;
    int num_threads = 5; // 生成するスレッドの数
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    thread_data_t *thread_data = malloc(num_threads * sizeof(thread_data_t));
    pthread_mutex_t lock;


    pthread_mutex_init(&lock, NULL);

    // 各スレッドのデータとスレッドの作成
    while (i < num_threads)
	{
        thread_data[i].lock = &lock;
        thread_data[i].thread_id = i + 1;

        // thread_data[i]の他の変数を初期化
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_data[i]);
		i++;
    }

	i = 0;
    // すべてのスレッドの終了を待つ
    while (i < num_threads)
	{
        pthread_join(threads[i], NULL);
		i++;
    }

    // リソースの解放
    pthread_mutex_destroy(&lock);
    free(threads);

	free(thread_data);

	return (0);
}