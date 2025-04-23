#include <stdio.h>
#include <math.h>

int main() {
    int cat1, cat2, hipo;
    printf("Informe, respectivamente, o valor do cateto 1 e do cateto 2: ");
    scanf("%d %d", &cat1, &cat2);

    hipo = sqrt((cat1 * cat1) + (cat2 * cat2));
    printf("Tamanho da hipotenusa: %d", hipo);
    return 0;
}