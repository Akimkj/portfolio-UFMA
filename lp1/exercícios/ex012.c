#include <stdio.h>
#define SQRT(x) x * x
int main() {
    int a = 3;
    int result = SQRT(a + 1);
    printf("O resultado é: %d\n", result);
    return 0;
}