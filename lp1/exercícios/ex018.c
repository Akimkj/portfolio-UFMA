#include <stdio.h>
#define CALC(a,b) a * b + a
int main() {
    int x = 2;
    int y = 5;
    int z = CALC(x + 1, y - 2);
    printf("z = %d", z);
    return 0;
}