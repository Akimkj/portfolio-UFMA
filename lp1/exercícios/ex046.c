#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    float peso, altura;
    char sexo;
    /*printf("Informe, respectivamente, a sua idade, sexo(m, f ou n), peso e altura: ");
    scanf("%d %c %f %f", &idade, &sexo, &peso, &altura);*/

    printf("Informe sua idade: ");
    scanf("%d", &idade);
    
    printf("\nInforme seu sexo (m, f ou n): ");
    scanf(" %c", &sexo);
    
    printf("\nInforme seu peso: ");
    scanf(" %f", &peso);
    
    printf("\nInforme sua altura: ");
    scanf(" %f", &altura);
    

    printf(" Sua idade: %d\n Seu sexo: %c\n Seu peso: %.2f\n Sua altura: %.2f\n", idade, sexo, peso, altura);
    
    return 0;
}