/*
* Arquivo para definição e especificação do TAD genérico Cofo, tipo de dado para coleção de variados tipos de dados.
* Modo de compilação: 
*
*
*/
#ifndef _GCOFO_H
#define _GCOFO_H
#include <stdlib.h>

/*Definição da estrutura do TAD genérico*/
typedef struct _gCofo_ Gcofo;
typedef struct _jogo_ Jogo;

/*Definições básicas*/
#define TRUE 1
#define FALSE 0
#define ERROR -999939899

/*Funções que implementam o TAD genérico*/

/*--------------------------
*Cria um novo Cofo
*
*pre-condição: maxItens > 0
*
*pos-condicao: retorna o novo Cofo ou retorna NULL caso falhe.
-------------------------------*/
Gcofo *GcofoCreate(int maxItens);

/*-------------------------
*Insere um novo item no Cofo
*
*pre-condicao: gCofo != NULL && o cofo não pode está cheio
*
*pos-condicao: retornar TRUE ou FALSE
----------------------------*/
int GcofoInsert(Gcofo *gcof, void* item);

/*------------------------------
*Destroi o Cofo 
*
*pre-condicao: gcof != NULL && gcof->numItens = 0
*
*pos-condicao: return TRUE ou FALSE
------------------------------*/
int GcofoDestroy(Gcofo *gcof);

/*------------------------------
*Esvazia o cofo
*
*pre-condicao: gcof != NULL
*
*pos-condicao: return TRUE ou FALSE
--------------------------------*/
int GcofoEmpty(Gcofo *gcof);

/*-----------------------
* Comparação de igualdade do param 1 pelo param 2
* 
* pre-condicao = param1 != NULL && param != NULL
*
* pos-condicao = TRUE or FALSE
*
----------------------------*/
//int cmp(void* param1, void* param2);

/*----------------------------
*Remove um elemento do cofo
*
*pre-condicão: gcof != NULL e gcof não pode está vazio.
*
*pos-condição: retornar o dado removido, caso encontre, senão retorna NULL
*
---------------------------------*/
Jogo *GcofoRemove(Gcofo *gcof, char *name);

/*-----------------------
*Consulta um elemento do cofo
*
*pre-condição: gcof != NULL e gcof não pode está vazio
*
*pos-condicao: retorna ou TRUE caso encontre, ou FALSE caso contrário.
--------------------------*/
int GcofoQuery(Gcofo *gcof, char *name);

/*-----------------------
*Pega o primeiro elemento de iteração do TAD (gcof->cur = 0)
*
* pre_condicao: gcof != NULL && gcof não pode está vazio 
*
*pos-condição: retornar o primeiro elemento da iteração do TAD ou NULL se não conseguir
------------------------*/
void *GcofoGetFirst(Gcofo *gcof);

/*-----------------------
*Pega o próximo elemento da iteração do TAD (gcof->cur++)
*
*pre-condicao: gcof != NULL && precisa ter um próximo elemento para iterar.
*
*pos-condicao: retornar o próximo elemento da iteração atual do TAD
--------------------------*/
void *GcofoGetNext(Gcofo *gcof);

#endif