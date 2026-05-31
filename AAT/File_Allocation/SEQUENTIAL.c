#include <stdio.h>

int main() {
    int n, start[20], length[20], i, j;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter starting block and length of file %d: ", i + 1);
        scanf("%d %d", &start[i], &length[i]);
    }

    printf("\nFile Allocation Table:\n");
    printf("File No\t   Start Block  \tLength  \tAllocated Blocks\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t", i + 1, start[i], length[i]);

        for(j = 0; j < length[i]; j++) {
            printf("%d ", start[i] + j);
        }

        printf("\n");
    }

    return 0;
}
