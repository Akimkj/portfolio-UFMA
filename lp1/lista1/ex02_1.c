#include <stdio.h>
void inverter(int number);

int main() {
    int num;
    scanf("%d", &num);
    
    inverter(num);

    return 0;
}

void inverter(int number) {
    while (number % 10 != 0) {
        printf("%d", number % 10);
        number /= 10;
    }
}
