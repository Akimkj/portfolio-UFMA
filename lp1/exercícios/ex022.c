#include <stdio.h>

int main() {
    int vet[] = {5, 43, 7, 67, 1, 45};
    int *ptr1 = vet;
    
    printf("%d\n", *ptr1 += 2);
    

    return 0;
}