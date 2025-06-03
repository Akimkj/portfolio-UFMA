#include <stdio.h>

int main() {
    int temp;
    printf("Digite uma temperatura: ");
    scanf("%d", &temp);

    if (temp < 0) {
        printf("tempo congelando");
    }
    else {
        if (temp >= 0 && temp < 10) {
            printf("tempo mt frio");
        }
        else if (temp >= 10 && temp < 20) {
            printf("tempo frio");
        }
        else if (temp >= 20 && temp < 30) {
            printf("normal");
        }
        else if (temp >= 30 && temp < 40) {
            printf("quente");
        }
        else {
            printf("muito quente");
        }
    }

    return 0;
}