#include <stdio.h>
/*letra - 65 ate 90 ou 97 ate 122
digito - 48 ate 57
caracter especial - restante
*/
int main() {
    char any;
    printf("digite um caracter: ");
    scanf("%c", &any);

    if (any >= '0' && any <= '9') {
        printf("digito");
    }
    else if ((any >= 'A' && any <= 'Z') || (any >= 'a' && any <= 'z')) {
        printf("letra");
    }
    else {
        printf("caracter especial");
    }
    return 0;
}