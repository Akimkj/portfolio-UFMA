#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main() {
    break; // NAO USAR
    continue; //NAO USAR
    i++; // certo
    ++i; // nao existe

    //tipos de dados primitivos
    int;
    char;
    float;
    double;
    void *;

    //tipos de dados não primitivos
    int a[10]; // 1d
    int b[5][5]; //2d
        /*Tensores
        - Listas
        - Arvores
        - Grafos
        */

    typedef struct _pessoa_ {
        int idade;
        char *nome;
        float altura;
    } Pessoa;


    //Estruturas de dados
    Pessoa people[10];

    
    return 0;
}