#include "queue.h"
#include "stack.h"
#include "stdio.h"

/*PRECISA DE CORRECAO*/
char *ConverteString(char *str, int n) {
    Queue *filatemp;
    Stack *stktemp;
    int i, j;
    char *caracter;
    if (str != NULL) {
        filatemp = qcCreate(n);
        stktemp = stkCreate(n);
        if (filatemp != NULL && stktemp != NULL) {
            i = 0;
            while (i < n) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    qcEnQueue(filatemp, (void*) &str[i]);
                }
                else if(str[i] >= '0' && str[i] <= '9') {
                    push(stktemp, (void*) &str[i]);
                }
                i++;
            }
            j = 0;
            caracter = (char*) qcDeQueue(filatemp);
            while (j < n && caracter != NULL) {
                str[j] = *caracter;
                caracter = (char*) qcDeQueue(filatemp);
                j++;
            }
        
            caracter = (char*) pop(stktemp);
            while(j < n && caracter != NULL) {
                str[j] = *caracter;
                caracter = (char*) pop(stktemp);
                j++;
            } 
            qcDestroy(filatemp);
            stkDestroy(stktemp);
            return str;
        }
    }
    return NULL;
}

int main() {
    char string[] = "A1E5T7W8G";

    char *string1 = ConverteString(string, 12);

    for (int i = 0; i < 12; i++) {
        printf("%c ", string1[i]);
    }

    return 0;
}