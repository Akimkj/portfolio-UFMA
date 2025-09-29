#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int op;
    printf("Escolha uma opção:\n");
    printf("\t1.iniciante\n");
    printf("\t2.medio\n");
    printf("\t3.dificil\n");
    scanf("%d", &op);

    if (op == 1) {
        printf("chato");
    }
    else if (op == 2) {
        printf("legal");
    }
    else {
        printf("perfeito");
    }

    printf("\n\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
    }

    return 0;
}