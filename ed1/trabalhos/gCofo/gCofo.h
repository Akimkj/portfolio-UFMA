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
*pre-condicao: gCofo != NULL && item != NULL
*
*pos-condicao: retornar TRUE ou FALSE
----------------------------*/
int GcofoInsert(Gcofo *gcof, void* item);

/*------------------------------
*Destroi o Cofo 
*
*pre-condicao: gcof->numItens = 0
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
int cmp(void* param1, void* param2);

/*----------------------------
*
*
*
*
*
*
*
*/

#endif