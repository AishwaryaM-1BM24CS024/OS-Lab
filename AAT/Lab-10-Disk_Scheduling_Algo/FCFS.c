#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, head, total = 0;
    int req[20];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");

    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++) {

        total += abs(req[i] - head);

        head = req[i];

        printf("-> %d ", head);
    }

    printf("\n\nTotal Head Movement = %d", total);

    return 0;
}
