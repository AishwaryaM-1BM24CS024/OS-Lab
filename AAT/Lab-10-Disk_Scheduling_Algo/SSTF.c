#include <stdio.h>
#include <stdlib.h>

int main() {

    int req[20], visited[20];
    int n, head, i, j;
    int total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");

    for(i = 0; i < n; i++) {

        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++) {

        int min = 9999;
        int index = -1;

        for(j = 0; j < n; j++) {

            if(!visited[j]) {

                int distance = abs(req[j] - head);

                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;

        total += abs(req[index] - head);

        head = req[index];

        printf("-> %d ", head);
    }

    printf("\n\nTotal Head Movement = %d", total);

    return 0;
}
