#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char option;

bool isInputCorrect(){
    if(option == 'A' || option == 'a' ||
       option == 'B' || option == 'b' ||
       option == 'C' || option == 'c')
        return true;
    else
        return false;
}

void menu(){
    printf("Bem vindo ao menu de escolhas\nTecle a letra correspondente a opcao desejada:\n\n");
    printf("Tecle A para saber os valores decimais correspondentes as letras (caseSensitive) da tabela ASCII\n");
    printf("Tecle B para saber os valores hexadecimais correspondentes aos numeros da tabela ASCII\n");
    printf("Tecle C para saber todos os numeros e letras(caseSensitive) existentes na tabela ASCII\n\n");
    printf("Obs: A entrada do usuario nao eh caseSensitive! :)\n");
    scanf("%c", &option);
}

void decides(){
    unsigned char ch;
    switch (option){
        case 'A': case 'a':
            printf("Valores decimais correspondentes as letras Maiusculas e minusculas: \n");
            for(ch = 0; ch < 255; ch++){
                if(ch >= 'A' && ch <= 'Z')
                    printf("%d ", ch);
                if(ch >= 'a' && ch <= 'z')
                    printf("%d ", ch);
            }
        break;
        case 'B': case 'b':
            printf("Valores Hexadecimais correspondentes aos numeros: \n");
            for(ch = 0; ch < 255; ch++){
                if(ch >= 'A' && ch <= 'Z')
                    printf("%x ", ch);
                if(ch >= 'a' && ch <= 'z')
                    printf("%x ", ch);
            }
        break;
        case 'C': case 'c':
            printf("Exibindo todas as letras e numeros contidos na tabela ASCII: \n");
            for(ch = 0; ch < 255; ch++){
                if(ch >= 'A' && ch <= 'Z')
                    printf("%c ", ch);
                if(ch >= 'a' && ch <= 'z')
                    printf("%c ", ch);
                if(ch >= '0' && ch <= '9')
                    printf("%c ", ch);
            }
        break;    
        default:
        printf("Digite uma entrada valida!");
        break;
    }
}

void main(){
    do{
        system("cls");
        menu();
    }
    while(!isInputCorrect());
    decides();
}