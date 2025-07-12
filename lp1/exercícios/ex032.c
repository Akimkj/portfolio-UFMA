#include <stdio.h>

typedef struct {
    int dia, mes, ano;
}Aniversario;

typedef struct {
    int idade;
    char sexo;
    char nome[100];
    Aniversario dataNas;
}Pessoa;

void imprimirPessoa(Pessoa a) {
    printf("Nome: %s\nIdade: %d\nData nascimento: %d/%d/%d\nSexo: %c\n", a.nome, a.idade, a.dataNas.dia, a.dataNas.mes, a.dataNas.ano, a.sexo);
}

Pessoa lerPessoa(Pessoa fulanoDeTown) {
    printf("seu nome: ");
    fgets(fulanoDeTown.nome, 100, stdin);
    printf("Digite sua data de nascimento(dia/mes/ano): ");
    scanf("%d %d %d", &fulanoDeTown.dataNas.dia, &fulanoDeTown.dataNas.mes, &fulanoDeTown.dataNas.ano);
    fulanoDeTown.idade = 2025 - fulanoDeTown.dataNas.ano;
    printf("Seu sexo: ");
    scanf(" %c", &fulanoDeTown.sexo);

    return fulanoDeTown;
}
int main() {
    Pessoa p1;
    p1 = lerPessoa(p1);

    imprimirPessoa(p1);
    
    return 0;
}