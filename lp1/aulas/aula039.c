#include <stdio.h>

int main() {
    int num;
    printf("Digite um inteiro: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("\nvalor negativo!\n\n");
    }
    printf("cabou...\n");
    

    return 0;
}