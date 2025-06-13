#include <stdio.h>

int main() {
    int vet[] = {2, 5, -1, 4, -1, 1};

    for (int i = 0; i < 6; i++) {
        if (vet[i] != -1) {
            vet[i] = i;
        }
    }

    for(int a= 0; a < 6; a++) {
        printf("%d ", vet[a]);
    }
    return 0;
}