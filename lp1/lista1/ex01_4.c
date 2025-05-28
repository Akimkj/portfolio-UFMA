#include <stdio.h>
#include <math.h>
int ehPrimo(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
                return 0;
        }
    }
    return 1;

}


int main() {
    int numero = 12;
    if (ehPrimo(numero)) {
        printf("eh primo");
    }
    else {
        printf("nao eh primo");
    }
    return 0;
}