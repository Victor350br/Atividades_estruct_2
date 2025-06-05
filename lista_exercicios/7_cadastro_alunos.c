#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define max 50

typedef struct{
    char nome[50];
    int matricula;
    float media;
}aluno;

int tot = 2;
aluno *alunos = NULL; 

void realocar(int n){
    if(n >= tot){
        tot *= 2;
        aluno *temp = realloc(alunos, tot * sizeof(aluno));
        if(temp != NULL){
            alunos = temp;
        }else{
            printf("\n>> Erro na alocação de memória.\n");
            return;
        }
    }
}

void cadastro(aluno *p, int n){
    printf("Nome do aluno: ");
    fgets(p->nome, max, stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;

    printf("Média do aluno: ");
    scanf("%f", &p->media);
    setbuf(stdin, NULL);
    p->matricula = n;
    
    printf("\n>> Cadastro realizado com sucesso.\n");
}

int main(){
    setlocale(LC_ALL, "");
    alunos = (aluno*)malloc(tot * sizeof(aluno));
    if(alunos == NULL){
        printf("\n>> Erro na alocação de memória.\n");
        return 1;
    }
    int n = 0;
    int opc = 0;

    do{
        printf("\n===== SISTEMA SIGAA =====\n");
        cadastro(&alunos[n], n);
        n++;
        printf("Deseja continuar? \n[1] Sim \n[0] Não \n>> ");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
        if(opc == 0){
            for(int x = 0; x < n; x++){
                if(alunos[x].media >= 7){
                    printf("\n===== %s =====\n", alunos[x].nome);
                    printf("Matrícula: %d\n", alunos[x].matricula);
                    printf("Média:     %.1f\n", alunos[x].media);
                }
            }
            break;
        }
        realocar(n);
    }while(1);
    free(alunos);
    return 0;
}

/*Cadastro de Alunos
Crie uma struct Aluno com nome, matrícula e média. Cadastre n alunos
e mostre os aprovados.*/