#include "stack.h"
#include "stdlib.h"
#include "stdio.h"

int VerificaString(char *cadeia, int n) {
    Stack *stktemp;
    char *caracter;
    int i, j;
    if (cadeia != NULL) {
        stktemp = stkCreate(n);
        if (stktemp != NULL) {
            i = -1, j = -1;
            while (i < n && j < n) {
                i++;
                while(cadeia[i] != '0') {
                    push(stktemp, (void*) &cadeia[i]);
                    i++;
                }
                j = i + 1;
                caracter = (char*) pop(stktemp);
                while (cadeia[j] != '0' && caracter != NULL) {
                    if (cadeia[j] != *caracter) {
                        stkDestroy(stktemp);
                        return FALSE;
                    }
                    j++;
                    caracter = (char*) pop(stktemp);
                }
            }
            stkDestroy(stktemp);
            return TRUE;
        }
    }
    return FALSE;
}

int main() {

    char *palavra = "22120212202212";

    if (VerificaString(palavra, 11)) {
        printf("siiiim");
    }
    else {
        printf("naooooo");
    }

    return 0;
}