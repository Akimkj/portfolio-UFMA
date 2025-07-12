#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    file = fopen("textinho.txt", "r");
    char letras;

    printf("O texto presente no arquivo: \n");
    while (!feof(file))
    {
        letras = fgetc(file);
        printf("%c", letras);
    }
    printf("\n");
    fclose(file);
    free(file);

    return 0;
}