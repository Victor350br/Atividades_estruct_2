#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define max 50

typedef struct{
    char nome[50];
    int numero;
}contato;

contato *contats = NULL;
int capac = 2; //capacidade inicial

void realocar(){
    capac *= 2;
    contato *temp = realloc(contats, capac*sizeof(contato));
    if(temp != NULL){
        contats = temp;
    }else{
        printf("\n> Erro na alocação de memória.\n\n");
        exit(1);
    }
}

void adicionar(contato *p, int *tot){
    if(*tot >= capac){
        realocar();
    }
    printf("\n===== ADICIONAR CONTATO =====\n");
    printf("Nome: ");
    fgets(p->nome, max, stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;

    printf("Número: ");
    scanf("%d", &p->numero);
    setbuf(stdin, NULL);

    *tot += 1;
    printf("\n>> Operação realizada com sucesso.\n\n");
}

void exibir(contato contats[], int tot){
    printf("\n===== LISTAGEM DE CONTATOS =====\n");
    for(int x = 0; x < tot; x++){
        printf("----- CONTATO %d -----\n", x+1);
        printf("Nome:     %-16s\n", contats[x].nome);
        printf("Número:   %-16d\n", contats[x].numero);
        printf("---------------------\n");
    }
}

void buscar(contato contats[], int tot){
    char nome[max];
    
    printf("\n===== BUSCA POR CONTATO =====\n");
    printf(">> Digite o nome do contato: ");
    fgets(nome, max, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    for(int x = 0; x < tot; x++){
        if(strcmp(nome, contats[x].nome) == 0){
            printf("\n----- RESULTADO -----\n");
            printf("Nome:     %-16s\n", contats[x].nome);
            printf("Número:   %-16d\n", contats[x].numero);
            printf("---------------------\n\n");
            return;
        }
    }
    printf("\n>> Contato não encontrado.\n\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    contats = (contato*)malloc(capac*sizeof(contato));
    int opc = 0, tot = 0;

    while(1){
        printf("\n===== LISTA DE CONTATOS =====\n");
        printf("[1] Adicionar \n[2] Buscar \n[3] Exibir \n[4] Sair \n>> ");
        scanf("%d", &opc);
        setbuf(stdin, NULL);

        switch(opc){
            case 1:
                adicionar(&contats[tot], &tot);
                break;
            case 2:
                if(tot > 0){
                    exibir(contats, tot);
                    buscar(contats, tot);
                }else{printf("\n>> Lista vazia.\n\n");}
                break;
            case 3:
                if(tot > 0){
                    exibir(contats, tot);
                }else{printf("\n>> Lista vazia.\n\n");}
                break;
            case 4:
                free(contats);
                return 0;
        }
    }
}

/*Agenda de Contatos
Crie uma struct Contato e permita adicionar, 
buscar por nome e exibir todos os contatos.*/