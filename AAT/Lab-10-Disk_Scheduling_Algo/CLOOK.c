#include <stdio.h>
#include <stdlib.h>

int main() {

    int req[20], n, head;
    int i, j, temp, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");

    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - i - 1; j++) {

            if(req[j] > req[j + 1]) {

                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int pos;

    for(i = 0; i < n; i++) {

        if(req[i] > head) {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    for(i = pos; i < n; i++) {

        total += abs(req[i] - head);

        head = req[i];

        printf("-> %d ", head);
    }

    total += abs(head - req[0]);

    head = req[0];

    printf("-> %d ", head);

    for(i = 1; i < pos; i++) {

        total += abs(req[i] - head);

        head = req[i];

        printf("-> %d ", head);
    }

    printf("\n\nTotal Head Movement = %d", total);

    return 0;
}
