#include <stdio.h>

int main() {
    int x, y;
    printf("informe o valor de x: ");
    scanf("%d", &x);

    if (x < 1) {
        y = x;
        printf("y = %d", y);
    }
    else if (x == 1) {
        y = 0;
        printf("y = %d", y);
    }
    else {
        y = x * x;
        printf("y = %d", y);
    }

    return 0;
}