/*
Arquivo para a especificação da TAD CofoInt, tipo de dado para uma coleção de inteiros

Processo de compilação:
gcc app.c CofoInt.c -o app
Para executar:
.\app.exe

*/
#ifndef __COFOINT_H
#define __COFOINT_H
#include <stdlib.h>

//Definições locais
typedef struct __cofo__ CofoInt;
#define TRUE 1
#define FALSE 0
#define ERROR -95356432

//Funções que implementam as operações da TAD CofoInt

/*-------------------------
Cria um novo TAD CofoInt

Pre-condição: maxItens > 0

Pos-condição: Retorna um endereço de um novo TAD CofoInt vazio ou NULL caso não consiga criar
--------------------------------*/
CofoInt *CreateCofoInt(int maxItens);


/*-----------------------------------------------------
Procura um item em um TAD CofoInt

pre-condicao: o CofoInt "cof" é um TAD criado pela função CreateCofoInt e o TAD CofoInt não pode estar vazio

pos-condição: retorna TRUE se conseguir encontrar o inteiro no TAD CofoInt, ou retorna FALSE caso não consiga encontrar.
----------------------------------------------------------*/
int CofoIntQuery(CofoInt *cof, int key);


/*--------------------------------------------
Inserir um inteiro ao TAD CofoInt

pre-condição: o CofoInt "cof" é um TAD criado pela função CreateCofoInt e o TAD CofoInt não pode está cheio.

pos-condição:retorna TRUE se conseguir adicionar um inteiro ao TAD CofoInt, ou retorna FALSE caso não consiga.
--------------------------------------------------*/
int CofoIntInsert(CofoInt *cof, int item);

/*-----------------------------------------------
Remove um inteiro do TAD CofoInt

pre-condição: o CofoInt "cof" é um TAD criado pela função CreateCofoInt e o TAD CofoInt não pode está vazio.

pos-condição: retorna o elemento removido ou ERROR se não conseguir remover.
-------------------------------------------------------*/
int CofoIntRemove(CofoInt *cof, int item);

/*------------------------------------------------------
Esvaziar um TAD CofoInt

pre-condicao: o CofoInt "cof" é um TAD criado pela função CreateCofoInt

pos-condicao: retorna TRUE se esvaziar e FALSE se não
----------------------------------------------------------------*/
int CofoIntEmpty(CofoInt *cof);


/*-----------------------------------------------
Destruir um TAD CofoInt

pre-condicao: o CofoInt "cof" é um TAD criado pela função CreateCofoInt e esse TAD está 

pos-condicao: TRUE se destruir e FALSE se não
---------------------------------------------------*/
int CofoIntDestroy(CofoInt *cof);



/*--------------------------------------------------
Pegar Quantidade Máxima de elementos do TAD CofoInt

pre-condicao: o CofoInt é um TAD criado pela função CreateCofoInt()

pos-condicao: retorna um inteiro representando a capacidade de armazenamento do cofo, ou retorna -1 caso não consiga.
---------------------------------------------- */
int getMaxItens(CofoInt *cof);


/*-------------------------------------------------------
Pegar Quantidade atual de elementos do TAD CofoInt 

pre-condição: o CofoInt é um TAD criado pela função CreateCofoInt()

pos-condicao: retorna um inteiro representando a quantidade atual de inteiros no cofo, ou retorna -1 caso não consiga.
*/
int getNumItens(CofoInt *cof);

/*-------------------------------------------
Exibir valor na posição especifica

pre-condicao: cof precisa ser criado pela funcao CreateCofoInt() e a posicao do indice precisa ser valida

pos-condicao: retorna o valor que está na posição do índice
-----------------------------------------------*/
int CofoIntGet(CofoInt *cof, int pos);

#endif