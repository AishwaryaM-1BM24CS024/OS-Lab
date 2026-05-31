#include <stdio.h>

int main() {

    int mainDir, subDir[20];
    int i, j;

    char dirName[20][30];
    char subName[20][20][30];

    printf("Enter number of main directories: ");
    scanf("%d", &mainDir);

    for(i = 0; i < mainDir; i++) {

        printf("\nEnter main directory name: ");
        scanf("%s", dirName[i]);

        printf("Enter number of subdirectories/files in %s: ", dirName[i]);
        scanf("%d", &subDir[i]);

        for(j = 0; j < subDir[i]; j++) {

            printf("Enter subdirectory/file %d name: ", j + 1);
            scanf("%s", subName[i][j]);
        }
    }

    printf("\nHierarchical Directory Structure:\n");

    for(i = 0; i < mainDir; i++) {

        printf("\n%s\n", dirName[i]);

        for(j = 0; j < subDir[i]; j++) {
            printf("   |-- %s\n", subName[i][j]);
        }
    }

    return 0;
}
