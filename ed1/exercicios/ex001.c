#include <stdio.h>
#define TRUE 1    
#define FALSE 0

int strSubString(char *sub, char *str, int nsub, int nstr) {
    int i = 0, j = 0;
    if (sub ==  NULL || str == NULL) {
        return FALSE;
    } 

    if (nsub > 0 && nstr > 0 && nsub <= nstr) {
        while (nstr > i && nsub > j) {
            while(sub[j] != str[i]) { 
                i++;
                j = 0;
            }
            i++;
            j++;
            if (nsub == j) {
                return TRUE;
            }
        }  
        return FALSE;
    }
    else {
        return FALSE;
    }
}


int main() {
    char strM[] = {"mikaMarquesDosSantos"};
    char subm[] = {"Marques"};      

    int op = strSubString(subm, strM, 6, 20);

    if (op) {
        printf("eh substring!\n");
    }
    else {
        printf("nao eh sub\n");
    }


    printf("\n\n");
    return 0;
}