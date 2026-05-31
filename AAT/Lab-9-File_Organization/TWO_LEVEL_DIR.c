#include <stdio.h>

int main() {

    int users, i, j, filesCount[20];
    char usersName[20][30];
    char files[20][20][30];

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i = 0; i < users; i++) {

        printf("\nEnter user %d name: ", i + 1);
        scanf("%s", usersName[i]);

        printf("Enter number of files for %s: ", usersName[i]);
        scanf("%d", &filesCount[i]);

        for(j = 0; j < filesCount[i]; j++) {

            printf("Enter file %d name: ", j + 1);
            scanf("%s", files[i][j]);
        }
    }

    printf("\nTwo Level Directory Structure:\n");

    for(i = 0; i < users; i++) {

        printf("\nUser: %s\n", usersName[i]);

        for(j = 0; j < filesCount[i]; j++) {
            printf("%s\n", files[i][j]);
        }
    }

    return 0;
}
