#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Elabore um algoritmo que receba, por meio do teclado, dois valores, um para a variável “a” e um para a variável “b”. Em seguida, faça os passos que julgar necessário para que ao final, a variável “a” possua o valor que inicialmente estava em “b” e a variável “b” possua o valor que inicialmente estava em “a”. Traduza seu algoritmo para a linguagem C e exiba os valores na tela.*/

int main() {
    int a, b, aux;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf(" %d", &b);

    aux = a;
    a = b;
    b = aux;

    printf("Valor de a: %d\nValor de b: %d\n", a, b);
    return 0;
}