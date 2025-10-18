#include <stdio.h>
#include <stdlib.h>
/*Faça um programa para ler do teclado uma quantidade de segundos e imprimir na tela a conversão para horas, minutos e segundos.*/
int main() {
    int totalSegundos, horas, minutos, segundos;
    printf("Digite a quantidade total em segundos: ");
    scanf("%d", &totalSegundos);

    horas = totalSegundos / 3600;
    minutos = (totalSegundos % 3600) / 60;
    segundos = totalSegundos - ((horas * 3600) + (minutos * 60));

    printf("%d:%d:%d", horas, minutos, segundos);

    return 0;
}