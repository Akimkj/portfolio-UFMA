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

int main() {
    Pessoa p1;
    /*printf("seu nome: ");
    fgets(p1.nome, 100, stdin);
    printf("Digite sua data de nascimento(dia/mes/ano): ");
    scanf("%d %d %d", &p1.dataNas.dia, &p1.dataNas.mes, &p1.dataNas.ano);
    p1.idade = 2025 - p1.dataNas.ano;
    printf("Seu sexo: ");
    scanf(" %c", &p1.sexo);

    printf("Nome: %s\nIdade: %d\nData nascimento: %d/%d/%d\nSexo: %c\n", p1.nome, p1.idade, p1.dataNas.dia, p1.dataNas.mes, p1.dataNas.ano, p1.sexo);*/
    printf("%d", sizeof(p1));
    return 0;
}