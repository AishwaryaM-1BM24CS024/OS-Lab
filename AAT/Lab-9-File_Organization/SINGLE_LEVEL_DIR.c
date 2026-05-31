#include <stdio.h>

int main() {

    int n, i;
    char files[20][30];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        printf("Enter file %d name: ", i + 1);
        scanf("%s", files[i]);
    }

    printf("\nFiles in Single Level Directory:\n");

    for(i = 0; i < n; i++) {
        printf("%s\n", files[i]);
    }

    return 0;
}
