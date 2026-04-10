#include <stdio.h>
#include <stdlib.h>

int *buffer;
int SIZE;
int in = 0, out = 0;
int mutex = 1;
int full = 0;
int empty;

void wait(int *s)
{
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void display()
{
    printf("\nBuffer: [ ");
    int i = out;
    for (int c = 0; c < full; c++)
    {
        printf("%d ", buffer[i]);
        i = (i + 1) % SIZE;
    }
    printf("]\n");
}

void producer()
{
    int item;

    printf("\n\nProducer tries to enter\n");

    wait(&mutex);
    printf("wait(mutex) -> mutex = %d\n", mutex);

    if (mutex < 0)
    {
        printf("Producer BLOCKED\n");
        signal(&mutex);
        return;
    }

    if (empty == 0)
    {
        printf("Buffer FULL, cannot produce\n");
        signal(&mutex);
        return;
    }

    wait(&empty);

    printf("\nProducer ENTERED critical section\n");

    printf("\nEnter item: ");
    scanf("%d", &item);

    buffer[in] = item;
    printf("\nProduced %d at position %d\n", item, in);

    in = (in + 1) % SIZE;

    printf("\nProducer leaving critical section\n");

    signal(&mutex);
    signal(&full);

    printf("signal(mutex) -> mutex = %d\n", mutex);
}

void consumer()
{
    int item;

    printf("\n\nConsumer tries to enter\n");

    wait(&mutex);
    printf("wait(mutex) -> mutex = %d\n", mutex);

    if (mutex < 0)
    {
        printf("Consumer BLOCKED\n");
        signal(&mutex);
        return;
    }

    if (full == 0)
    {
        printf("Buffer EMPTY, cannot consume\n");
        signal(&mutex);
        return;
    }

    wait(&full);

    printf("\nConsumer ENTERED critical section\n");

    item = buffer[out];
    printf("\nConsumed %d from position %d\n", item, out);

    out = (out + 1) % SIZE;

    printf("\nConsumer leaving critical section\n");

    signal(&mutex);
    signal(&empty);

    printf("signal(mutex) -> mutex = %d\n", mutex);
}

void both()
{
    int item;

    printf("\n\nProducer and Consumer arrive together\n");

    printf("\nProducer tries to enter\n");
    wait(&mutex);
    printf("wait(mutex) -> mutex = %d\n", mutex);

    printf("\nProducer ENTERED critical section\n");

    printf("\nConsumer tries to enter at same time\n");
    wait(&mutex);
    printf("wait(mutex) -> mutex = %d\n", mutex);

    if (mutex < 0)
    {
        printf("Consumer BLOCKED (cannot enter critical section)\n");
    }

    if (empty == 0)
    {
        printf("\nBuffer FULL, Producer cannot proceed\n");
    }
    else
    {
        wait(&empty);

        printf("\nEnter item: ");
        scanf("%d", &item);

        buffer[in] = item;
        printf("\nProduced %d at position %d\n", item, in);

        in = (in + 1) % SIZE;
    }

    printf("\nProducer leaving critical section\n");

    signal(&mutex);
    printf("signal(mutex) -> mutex = %d\n", mutex);

    signal(&full);

    printf("\nConsumer wakes up and enters critical section\n");

    if (full == 0)
    {
        printf("Buffer EMPTY, cannot consume\n");
        signal(&mutex);
        return;
    }

    wait(&full);

    item = buffer[out];
    printf("\nConsumed %d from position %d\n", item, out);

    out = (out + 1) % SIZE;

    printf("\nConsumer leaving critical section\n");

    signal(&mutex);
    signal(&empty);

    printf("signal(mutex) -> mutex = %d\n", mutex);
}

int main()
{
    int choice;

    printf("Enter buffer size: ");
    scanf("%d", &SIZE);

    buffer = (int *)malloc(SIZE * sizeof(int));
    empty = SIZE;

    while (1)
    {
        printf("\n\n-----------------------------\n");
        printf("1. Produce\n2. Consume\n3. Both (simulate preemption)\n4. Exit\n");
        printf("-----------------------------\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            producer();
            display();
        }
        else if (choice == 2)
        {
            consumer();
            display();
        }
        else if (choice == 3)
        {
            both();
            display();
        }
        else if (choice == 4)
        {
            free(buffer);
            return 0;
        }
        else
        {
            printf("\nInvalid choice\n");
        }
    }
}
