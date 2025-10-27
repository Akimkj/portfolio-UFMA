#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*Faça um algoritmo que recebe uma pilha armazenada em um 
vetor, um valor (chave), e uma função de comparação, e remove 
respeitando a disciplina de acesso da pilha todos os elementos até 
encontrar um com chave menor que o valor da chave recebida. 
Não pode usar pops e push, e deve obedecer a disciplina de 
acesso da pilha. É uma função interna do TAD Pilha. 
int RemoveMaioresQueKey (Stack *s, void *key, int (*cmp) 
(void *, void *)) 
OBS: cmp (a,b) retorna TRUE se a < b e False caso contrário */

typedef struct _pessoa_ {
    char *nome;
    int idade;
} Pessoa;

int cmp_pessoa_idade(void *key, void *data) {
    int *idadeLimite = (int*) key;
    Pessoa *pessoa = (Pessoa*) data;
    if (pessoa->idade < *idadeLimite) {
        return TRUE;
    }
    return FALSE;
}


/*A main tem problemas de implementação,falta corrigir*/
int main() {
    Stack *stk;
    int max = 4;
    stk = stkCreate(max);

    printf("\n======informações pessoas====\n");
    
    // Aloca e cadastra as pessoas
    Pessoa *p1 = (Pessoa*) malloc(sizeof(Pessoa));
    p1->nome = "mika";
    p1->idade = 45;
    
    Pessoa *p3 = (Pessoa*) malloc(sizeof(Pessoa));
    p3->nome = "diogo";
    p3->idade = 99;

    Pessoa *p4 = (Pessoa*) malloc(sizeof(Pessoa));
    p4->nome = "marina";
    p4->idade = 13;

    Pessoa *p5 = (Pessoa*) malloc(sizeof(Pessoa));
    p5->nome = "gabriel";
    p5->idade = 67;

    // INSERE NA ORDEM CORRETA PARA TESTE
    // A pilha é LIFO, então o último inserido será o topo
    push(stk, p1);  // Base: mika(45)
    push(stk, p3);  // diogo(99)
    push(stk, p4);  // marina(13)  
    push(stk, p5);  // Topo: gabriel(67)

    printf("Ordem na pilha (do topo para base):\n");
    printf("Esperado: gabriel(67), marina(13), diogo(99), mika(45)\n");

    printf("\n======Retirando os velhos até encontrar um novinho========\n");
    int idadeLimite = 18; 
    int removidos = RemoveMaioresQueKey(stk, &idadeLimite, cmp_pessoa_idade);
    
    printf("Elementos removidos: %d\n", removidos);
    printf("Esperado: 1 (apenas gabriel)\n");

    // VERIFICAÇÃO: Imprime o que restou na pilha
    printf("\n======Elementos restantes na pilha:======\n");
    
    // Array para guardar todos os ponteiros e liberar memória depois
    Pessoa *todasPessoas[] = {p1, p3, p4, p5};
    
    // Para verificar o conteúdo sem usar pops que destruiriam a pilha
    // Criamos uma pilha temporária
    Stack *temp = stkCreate(max);
    int count = 0;
    
    // Transfere da pilha original para temporária imprimindo
    Pessoa *p;
    while ((p = pop(stk)) != NULL) {
        printf("%s (%d anos)\n", p->nome, p->idade);
        push(temp, p);
        count++;
    }
    
    // Devolve os elementos para a pilha original
    while ((p = pop(temp)) != NULL) {
        push(stk, p);
    }
    stkDestroy(temp);
    
    printf("Total de elementos restantes: %d\n", count);
    printf("Esperado: 3 (marina, diogo, mika)\n");

    // Limpeza final - libera todos os elementos
    for (int i = 0; i < 4; i++) {
        free(todasPessoas[i]);
    }
    stkDestroy(stk);
    
    return 0;
}
