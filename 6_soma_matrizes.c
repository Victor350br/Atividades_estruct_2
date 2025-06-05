#include <stdio.h>
#include <locale.h>

#define lin 3
#define col 3

int main(){
    setlocale(LC_ALL, "");
    int mat1[lin][col]={
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5}};
    int mat2[lin][col]={
        {4, 5, 6},
        {5, 6, 7},
        {6, 7, 8}};
    int result[lin][col];
    int l = 0, c = 0;

    for(l = 0; l < lin; l++){
        for(c = 0; c < col; c++){
            result[l][c] = mat1[l][c] + mat2[l][c];
        }
    }

    for(l = 0; l < lin; l++){
        for(c = 0; c < col; c++){
            printf("[%d] ", result[l][c]);
        }
        printf("\n");
    }
    return 0;
}

/*Soma de Matrizes
Crie duas matrizes 3x3, some seus valores e exiba o resultado.*/