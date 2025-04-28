#include <stdio.h>
#include <math.h>
int main(){
    float a = 0.0;
    double b = 0.0; 
    a = sqrt(27.0) ;
    b = sqrt(27.0) ;
    if (a == b)
        printf ("Sao iguais, %f e %lf", a, b);

    else
        printf ("Sao diferentes, %.17f e %.17lf", a, b);
    return 0;
    /*A resposta nessa questão é que entra no else, pois, apesar do float e do double servirem para representar valores reais, a precisão de float é mais limitada por reservar 32 bits de memoria, enquanto double utiliza 64 bits, logo, o resultado de double é mais preciso e mais correto doq o do float, que mostra casas decimais diferentes após a 6/7 casa decimal, e se comparar com o resultado de uma calculadora, o do double é mais preciso.*/
}
 