#include <stdio.h>

int main() {
    char nome[] = "bom dia";
    

    char *ptr1;
    ptr1 = nome;
    
    while (*ptr1 != '\0') {
        if (*ptr1 >= 'a' && *ptr1 <= 'z') {
            *ptr1 -= ('a' - 'A');
        }
        ptr1++;
    }
    printf("maius = %s", nome);
    return 0;
}