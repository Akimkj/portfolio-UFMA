#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
}Aluno;

//Função auxiliar
void preencherAlunos(char f[], Aluno vetAlunos[]) {
    FILE *fileOrigin = fopen(f, "r");
    char linha[300];
    int i = 0;
    while(fgets(linha, sizeof(linha), fileOrigin)) {
        if (linha[0] == '#') {
            continue;
        }

        if (sscanf(linha, "%s %d %f %f", vetAlunos[i].nome, &vetAlunos[i].matricula, &vetAlunos[i].nota1, &vetAlunos[i].nota2) == 4) {
            i++;
        } 
    }
    
    fclose(fileOrigin);
} 

//Função principal
void salvarAlunos(Aluno alunos[], int numAlunos, const char* nomeArquivo) {
    FILE *mainFile = fopen(nomeArquivo, "w");
    int count = 0;
    while (count < numAlunos) {
        fprintf(mainFile, "\nNome: %s\tMatricula: %d\tNota 1: %.2f\tNota 2: %.2f", alunos[count].nome, alunos[count].matricula, alunos[count].nota1, alunos[count].nota2);
        count++;
    }
    fclose(mainFile);
}

int main() {
    char arquivoBase[] = {"alunos.txt"};
    int quantAlunos = 4;
    Aluno alunos[quantAlunos];
    preencherAlunos(arquivoBase, alunos);

    char saveAlunos[] = {"dados_alunos.txt"};

    salvarAlunos(alunos, quantAlunos, saveAlunos);
    
    
}