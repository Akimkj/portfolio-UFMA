#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    float peso, altura;
    char sexo;
    printf("Informe, respectivamente, a sua idade, peso, altura e sexo(m, f ou n): ");
    scanf("%d %f %f %c", &idade, &peso, &altura, &sexo);


    printf(" Sua idade: %d\n Seu sexo: %c\n Seu peso: %.2f\n Sua altura: %.2f\n", idade, sexo, peso, altura);
    
    return 0;
}