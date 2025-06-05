#include <stdio.h>
#include <locale.h>

#define max 4

int main(){
    setlocale(LC_ALL, "Portuguese");
    int matriz[max][max] = {
        {1,  2,  3,  4 },
        {5,  6,  7,  8 },
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    int soma = 0;

    for(int x = 0; x < max; x++){
        soma += matriz[x][x];
    }
    printf("A soma da diagonal principal é %d\n", soma);

    return 0;
}

/*Soma Diagonal Principal
Crie uma matriz 4x4 e calcule a soma da diagonal principal.*/