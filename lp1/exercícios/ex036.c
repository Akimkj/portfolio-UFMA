#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void escrever(char f[]);
void ler(char f[]);

int main() {
    char nome[] = {"textinho.txt"};
    //escrever(nome);
    ler(nome);
    
    return 0;
}


void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char letras;
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

void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char texto[500];

    printf("O texto presente no arquivo: \n");
    while (fgets(texto, sizeof(texto), file))
    {
        printf("--> %s", texto);
    }
    printf("\n");
    fclose(file);
    free(file);
}