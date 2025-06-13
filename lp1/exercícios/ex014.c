#include <stdio.h>

int ehPalindromo(int num) {
    int aux = num, tamanho = 0;
    while (aux % 10 != 0) {
        aux /= 10;
        tamanho++;
    }

    int vetNum[tamanho];

    for (int a = tamanho - 1; a >= 0; a--) {
        vetNum[a] = (num % 10);
        num /= 10;
    }
    printf("%d\n", sizeof(vetNum));
    for (int b = 0; b < tamanho; b++) {
        printf("%d ", vetNum[b]);
    }
    int i = 0, j = tamanho - 1;

    while (i < j) {
        if (vetNum[i] != vetNum[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main() { 
    int numero = 7667;

    if (ehPalindromo(numero)) {
        printf("\n eh palindromo");
    }
    else {
        printf("\n nao eh palindromo");
    }
    
    return 0;
}