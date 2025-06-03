#include <stdio.h>

int main() {
    char vitamina;
    scanf("%c", &vitamina);
    
    switch (vitamina) {
        case 'a': printf("Olho\n"); break;
        case 'b': printf("sei la\n"); break;
        case 'c': printf("saude\n"); break;
        case 'd': printf("sol\n"); break;
        default: printf("nenhuma vitamina detectada!\n"); break;
    }

    return 0;
}