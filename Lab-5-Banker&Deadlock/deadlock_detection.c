#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m];
    int finish[n], safeSeq[n];

    printf("Enter the allocation matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i);

        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the request matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i);

        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    // Initialize finish array
    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                    {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    if(count == n)
    {
        printf("\nSystem is in safe state.\n");
        printf("Safe Sequence is: ");

        for(i = 0; i < n; i++)
        {
            printf("P%d", safeSeq[i]);

            if(i != n - 1)
                printf(" ");
        }

        printf("\n");
    }
    else
    {
        printf("\nDeadlock detected.\nProcesses in deadlock are: ");

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}
