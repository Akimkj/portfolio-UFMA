#include <stdio.h>

int main(){
    int num;
    printf("Digite um inteiro: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("Par!");
    }
    else {
        printf("Ímpar");
    }


    return 0;
}