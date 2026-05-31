#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, diskSize;
    int i, j, temp, total = 0, pos = 0;
    char direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    printf("Enter direction (L for Left, R for Right): ");
    scanf(" %c", &direction);

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(req[j] > req[j + 1]) {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    pos = n;
    for(i = 0; i < n; i++) {
        if(req[i] > head) {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    if(direction == 'R' || direction == 'r') {

        for(i = pos; i < n; i++) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }

        total += abs((diskSize - 1) - head);
        head = diskSize - 1;
        printf("-> %d ", head);

        for(i = pos - 1; i >= 0; i--) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    else if(direction == 'L' || direction == 'l') {

        for(i = pos - 1; i >= 0; i--) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }

        total += abs(0 - head);
        head = 0;
        printf("-> %d ", head);

        for(i = pos; i < n; i++) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    else {
        printf("\nInvalid Direction\n");
        return 0;
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}
