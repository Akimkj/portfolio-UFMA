#include <stdio.h>

int main() {
    int quantDias, anos, meses, dias;
    scanf("%d", &quantDias);
    anos = quantDias / 365;
    meses =  (quantDias - (anos * 365)) / 30;
    dias = quantDias - ((meses * 30) + (anos * 365));

    printf("%d:%d:%d\n", anos, meses, dias);
    return 0;
}