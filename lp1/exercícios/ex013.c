#include <stdio.h>

int main() {
    int n, soma = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) {
        soma += i;
    }
    printf("%d", soma);
    return 0;
}