#include <stdio.h>

void fun(int y) {y = 30;}

int main() {
    int x = 20;
    fun(x);
    printf("%d\n", x);
    return 0;
}