#include <stdio.h>
#include <locale.h>

#define max 5

int main(){
    setlocale(LC_ALL, "");
    int vet1[max] = {1,2,3,4,5};
    int vet2[max] = {1,3,5,7,9};
    int inter[max];
    int tot = 0;

    for(int x = 0; x < max; x++){
        for(int y = 0; y < max; y++){
            if(vet1[y] == vet2[x]){
                inter[tot] = vet1[y];
                tot++;
            }
        }
    }
    printf("\n>> Elementos do vetor A: ");
    for(int a = 0; a < max; a++){
        printf("%d ", vet1[a]);
    }
    printf("\n>> Elementos do vetor B: ");
    for(int b = 0; b < max; b++){
        printf("%d ", vet2[b]);
    }
    if(tot > 0){
        printf("\n>> Dentre os elementos, há em comum: ");
        for(int i = 0; i < tot; i++){
            printf("%d ", inter[i]);
        }
    }else{printf("\n>> Não há elementos em comum.");}
    return 0;
}


/*Interceção de Vetores
Dado dois vetores de inteiros, mostre os elementos comuns entre eles.*/