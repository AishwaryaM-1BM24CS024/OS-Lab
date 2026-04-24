#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];
pthread_t philosophers[N];

void* philosopher(void* num)
{
    int id = *(int*)num;
    int left = id;
    int right = (id + 1) % N;

    while (1)
    {
        printf("Philosopher %d is THINKING\n", id);
        sleep(1);

        if (id % 2 == 0)
        {
            // Even → left then right
            pthread_mutex_lock(&forks[left]);
            printf("P%d picked LEFT fork %d\n", id, left);

            pthread_mutex_lock(&forks[right]);
            printf("P%d picked RIGHT fork %d\n", id, right);
        }
        else
        {
            // Odd → right then left
            pthread_mutex_lock(&forks[right]);
            printf("P%d picked RIGHT fork %d\n", id, right);

            pthread_mutex_lock(&forks[left]);
            printf("P%d picked LEFT fork %d\n", id, left);
        }

        printf("Philosopher %d is EATING\n", id);
        sleep(2);

        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);

        printf("P%d released forks %d and %d\n\n", id, left, right);
    }

    return NULL;
}

int main()
{
    int ids[N];

    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
        ids[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
