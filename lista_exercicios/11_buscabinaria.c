#include <stdio.h>
#include <locale.h>

int busca_binary(int vet[], int tam, int chave){
    int inicio = 0;
    int fim = tam;
    int meio = 0;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(vet[meio] == chave){
            return meio;
        }else if(vet[meio] < chave){
            inicio = meio + 1;
        }else{
            inicio = meio - 1;
        }
    }
    return -1;
}

int main(){
    setlocale(LC_ALL, "");
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int tam = (sizeof(vetor) / sizeof(vetor[0])) - 1;
    int chave = 7;
    int pos = busca_binary(vetor, tam, chave);
    if(pos != -1){
        printf("Número encontrado na posição %d.\n", pos);
    }else{
        printf("Número não encontrado.\n");
    }

    return 0;
}

/*Busca Binária
Implemente busca binária em um vetor ordenado.*/