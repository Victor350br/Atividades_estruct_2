#include <stdio.h>
#include <string.h>
#include <locale.h>

#define max 30

int verificador(char p[], char letra, int tam){
    int cont = 0;
    for(cont = 0; cont < tam; cont++){
        if(letra == p[cont]){
            return 1;
        }
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    char palavra[max] = "python";
    char acertos[max] = " ";
    char jafoi[max] = " ";
    char erros[max] = "O|/\\/\\"; //desenhar o boneco
    int ac = 0;
    int ganhou = 0;
    int er = 0;
    int n = 0;
    char letra = ' ';
    int tam = strlen(palavra);
    int cont = 0;

    printf("\n===== JOGO DA FORCA =====\n");
    printf("Tema: Programação\n");
    while(1){
        printf("________________\n");
        printf("||             |  \n");
        printf("||             %c \n", (er > 0) ? erros[0] : ' ');
        printf("||            %c%c%c\n", (er > 2) ? erros[2] : ' ', 
            (er > 1) ? erros[1] : ' ', (er > 3) ? erros[3] : ' ');
        printf("||            %c %c\n", 
            (er > 4) ? erros[4] : ' ', (er > 5) ? erros[5] : ' ');
        printf("||\n||\n");
        printf("==========\n");
        
        if(n > 0){
            printf("\n[ ");
            for(cont = 0; cont < n; cont++){
                printf("%c ", jafoi[cont]);
            }
            printf("]\n\n");
        }

        for(cont = 0; cont < tam; cont++){
            if(strchr(acertos, palavra[cont])){
                printf("%c ", palavra[cont]);
            }else{
                printf("_ ");
                ganhou = 0;
            }
        }

        if(ganhou == 1){
            printf("\n>> Parabéns, você ganhou!\n\n");
            return 0;
        }else if(er > 5){
            printf("\n>> Sinto muito, você perdeu!\n");
            printf("A palavra correta era: %s\n\n", palavra);
            return 0;
        }

        printf("\n\nDigite uma letra. \n>> ");
        scanf("%c", &letra);
        setbuf(stdin, NULL);

        if(strchr(jafoi, letra)){
            er++;
        }else if(verificador(palavra, letra, tam)){
            acertos[ac] = letra;
            jafoi[n] = letra;
            n++;
            ac++;
            ganhou = 1;
        }else{
            jafoi[n] = letra;
            n++;
            er++;
        }
    }
}
/*Jogo da Forca (Console)
Desenvolva um jogo simples da forca no 
terminal, usando vetores e controle de fluxo.*/