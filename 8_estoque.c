#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define max 50

typedef struct{
    char nome[max];
    int codigo;
    int quant;
    float preco;
}produto;

produto *prods = NULL;
int capac = 2; //capacidade inicial

void realocar(){
    capac *= 2;
    produto *temp = realloc(prods, capac * sizeof(produto));
    if(temp != NULL){
        prods = temp;
    }else{
        printf("\n>> Falha na aloca��o de mem�ria.\n\n");
        exit(1);
    }
}

void cadastro(produto *p, int *tot){
    if(*tot >= capac){
        realocar();
    }

    printf("\n===== CADASTRO DE PRODUTOS =====\n");
    printf("Nome: ");
    fgets(p->nome, max, stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;

    p->codigo = *tot + 1;

    printf("Quantidade: ");
    scanf("%d", &p->quant);
    setbuf(stdin, NULL);

    printf("Pre�o: R$");
    scanf("%f", &p->preco);
    setbuf(stdin, NULL);

    *tot = *tot + 1;

    printf("\n>> Opera��o realizada com sucesso.\n\n");
}

void listar(produto prods[], int tot){
        printf("\n================== LISTAGEM DE ITENS ==================\n");
        printf("%-9s       %-9s       %-9s       %-9s\n", 
            "Nome", "C�digo", "Quantidade", "Pre�o");
        printf("-------------------------------------------------------\n");
    for(int x = 0; x < tot; x++){
        printf("%-9s       %-9d       %-9d       R$%-9.2f\n", 
            prods[x].nome, prods[x].codigo, prods[x].quant, prods[x].preco);
        printf("-------------------------------------------------------\n");
    }
}

void buscar(produto prods[], int tot){
    int cod = 0;
    printf("\n===== BUSCA POR PRODUTO =====\n");
    printf("Digite o c�digo: ");
    scanf("%d", &cod);
    setbuf(stdin, NULL);
    if(cod >= 1 && cod <= tot){
        cod--;
        printf("\n===== PRODUTO ESCOLHIDO =====\n");
        printf("Nome:          %2s\n", prods[cod].nome);
        printf("Pre�o:       R$%.2f\n", prods[cod].preco);
        printf("C�digo:        %-2d\n", prods[cod].codigo);
        printf("Quantidade:    %-2d\n", prods[cod].quant);
        printf("-------------------\n");
        return;
    }else{printf("\n>> Produto n�o encontrado.\n\n");}
}

int main(){
    setlocale(LC_ALL, "");
    prods = (produto*)malloc(capac * sizeof(produto));
    if(prods == NULL){
        printf("\n>> Falha na aloca��o de mem�ria.\n\n");
        return 1;
    }
    int opc = 0;
    int tot = 0;
    while(1){
        printf("\n===== NOSSO ATACAREJO =====\n");
        printf("[1] Cadastrar \n[2] Buscar \n[3] Listar \n[4] Sair \n>> ");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
        switch(opc){
            case 1:
                cadastro(&prods[tot], &tot);
                break;
            case 2:
                if (tot > 0) { 
                    listar(prods, tot);
                    buscar(prods, tot);
                }
                else{ printf("\n>> Lista vazia.\n\n");}
                break;
            case 3:
                if (tot > 0) { listar(prods, tot);}
                else{ printf("\n>> Lista vazia.\n\n");}
                break;
            case 4:
                free(prods);
                return 0;
        }
    }
}

/*Estoque Simples
Crie uma struct Produto com nome, c�digo, quantidade 
e pre�o. Permita cadastrar, buscar e listar produtos.*/