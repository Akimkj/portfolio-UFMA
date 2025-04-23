#include <stdio.h>
#include <math.h>
int main() {
    float x1, x2, y1, y2;
    printf("Digite respectivamente os valores dos pares ordenados (x1, y1, x2, y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    float distancia = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    printf("A distancia entre os dois pontos e de: %.2f unidades.", distancia);

    return 0;
}