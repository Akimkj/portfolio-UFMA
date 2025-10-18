#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Coração é uma belíssima onda");

    return 0;
}