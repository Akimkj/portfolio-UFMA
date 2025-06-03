#include <stdio.h>

int soma_digitos(int num) {
    if (num%10 == num) {
        return num;
    }
    else {
        return (num%10) + soma_digitos(num/10);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", soma_digitos(n));
    return 0;
}