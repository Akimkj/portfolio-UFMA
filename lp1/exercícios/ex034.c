#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    file = fopen("textinho.txt", "w");
    char letras;
    if(file) {
        printf("Escreva uma pequena biografia sobre você, e depois digita ENTER: ");
        scanf("%c", &letras);
        while (letras != '\n')
        {
            fputc(letras, file);
            scanf("%c", &letras);
        }
        fclose(file);
        free(file);
        
    }
    else {
        printf("Falha ao abrir arquivo!");
    }
    return 0;
}