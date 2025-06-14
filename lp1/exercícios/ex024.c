#include <stdio.h>

int main() {
    char str[] = "Mika Marques";
    char *ptr1 = str;

    while (*ptr1 != '\0')
    {
        printf("%c ", *ptr1);
        ptr1++;
    }
    return 0;
}