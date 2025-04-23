#include <stdio.h>

int main() {
    int num;
    printf("Informe um valor: ");
    scanf("%d", &num);

    if ((num % 5 == 0) && (num % 3 == 0)) {
        printf("%d e divisivel por 5 e por 3 ao mesmo tempo!", num);
    }
    else {
        printf("%d NAO e divisivel por 5 e por 3 ao mesmo tempo.", num);
    }
    return 0;
}