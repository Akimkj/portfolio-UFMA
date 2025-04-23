#include <stdio.h>

int main() {
    double tempC, tempF;
    printf("Informe uma temperatura em Fahrenheit: ");
    scanf("%lf", &tempF);

    tempC = ((tempF - 32) * 5)/9;
    printf("A temperatura em Celsius: %.4lf C", tempC);

    return 0;
}