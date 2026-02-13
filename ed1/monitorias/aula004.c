#include <stdio.h>
#define possui 1
#define TRUE 1
#define FALSE 0

int SUBSTRING(char *string, char *substring, int length); 

int main(){
    char string[] = {"marina veiga"};
    char substring[] = {"mar"}; 

    int tam = sizeof(string)/sizeof(string[0]);

    int resultado = SUBSTRING(string,substring,tam);

    if (resultado == possui){
        printf("Contem substring");
    }
    else{
        printf("Nao contem substring");
    }
    
    return 0;
}

/*int SUBSTRING(char *string, char *substring, int length){
    int flag = 0;
    char *auxSub;
    char *auxString;

    for(int i = 0; i< length; i++){
        auxSub = substring;
        auxString = string; 
        while(*auxSub != '\0' && *auxString == *auxSub){ 
            auxString++;
            auxSub++;
        }

        if(*auxSub == '\0'){
            flag = TRUE;
        }
        else{
            flag = FALSE;
        }
        string++;

        if (flag == TRUE){
            i = length;
        }
    }

    return flag;
}*/

#include <stdio.h>

int SUBSTRING(char *string, char *substring, int length){
    int i, j;

    for (i = 0 ; string[i] != '\0' ;i++){
        for(j = 0; j < '\0' && string[i + j] == substring[j]; j++){
            
        }
        if (j == '\0'){
            return 1;
        }
        

    }
    return 0;
}