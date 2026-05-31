#include <stdio.h>

int main() {
    int n, i, j;
    int indexBlock[20], blocks[20][20], count[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("\nEnter index block for file %d: ", i + 1);
        scanf("%d", &indexBlock[i]);

        printf("Enter number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &count[i]);

        printf("Enter the blocks allocated: ");

        for(j = 0; j < count[i]; j++) {
            scanf("%d", &blocks[i][j]);
        }
    }

    printf("\nFile Allocation Table:\n");
    printf("File No\t   Index Block\t   Allocated Blocks\n");

    for(i = 0; i < n; i++) {

        printf("%d\t\t%d\t\t", i + 1, indexBlock[i]);

        for(j = 0; j < count[i]; j++) {
            printf("%d ", blocks[i][j]);
        }

        printf("\n");
    }

    return 0;
}
