#include <stdio.h>

int main() {

    int n, i, j;
    int start[20], count[20], blocks[20][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("\nEnter starting block of file %d: ", i + 1);
        scanf("%d", &start[i]);

        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &count[i]);

        printf("Enter linked blocks: ");

        for(j = 0; j < count[i]; j++) {
            scanf("%d", &blocks[i][j]);
        }
    }

    printf("\nFile Allocation Table:\n");
    printf("File No\t   Start Block\t   Linked Blocks\n");

    for(i = 0; i < n; i++) {

        printf("%d\t\t%d\t\t", i + 1, start[i]);

        for(j = 0; j < count[i]; j++) {

            printf("%d", blocks[i][j]);

            if(j != count[i] - 1) {
                printf(" -> ");
            }
        }

        printf("\n");
    }

    return 0;
}
