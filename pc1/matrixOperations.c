#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define n 2

int m1[n][n], m2[n][n], result[n][n];
char option;
int marcador = 0;
int k;

/**
*Metodo vazio responsavel por receber os valores do user
*@param x[n][n]
*@param mat
*/
void getElements(int x[n][n], int mat){
    printf("Entre com os elementos da matriz %d\n", mat);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){   
            printf("Posicao(%d, %d): ", i, j);
            scanf("%d",&x[i][j]);            
        }
    }
}

/**
*Metodo booleano resposavel por condicionar a limpeza de tela 
*/
bool clear(){
    if(option == 'e' || option == 'E')
        return false;
    else
        return true;
}
/**
*Metodo booleano responsavel por condicionar a quebra do loop interno no main()
*/
bool isInputCorrect(){
    if(option == 'A' || option == 'a' || option == 'B' || option == 'b' || option == 'C' || option == 'c' ||
    option == 'D' || option == 'd' || option == 'E' || option == 'e' || option == 'F' || option == 'f' || option == '!' )
        return false;
    else
        return true;
}

/**
*Metodo responsavel por imprimir o menu que interage com o user
*/
void menu(){
    if(clear())
        system("cls");
    if(marcador == 0)
        printf("Bem vindo ao menu de escolhas\nOs valores das matrizes foram recebidos com sucesso!\n");
    else
        printf("Novos valores das matrizes salvos! Deseja realizar mais alguma operacao?\n");
    printf("Tecle a letra correspondente a operacao desejada:\n\n");
    printf("Tecle A para somar as duas matrizes\n");
    printf("Tecle B para subtrair a primeira matriz da segunda\n");
    printf("Tecle C para adicionar uma constante as duas matrizes\n");
    printf("Tecle D para executar o produto matricial C = A . B\n");
    printf("Tecle E para imprimir o resultado\n");
    printf("Tecle ! para finalizar o programa\n");
    getchar();
    scanf("%c", &option);
}

/**
*Metodo responsavel pela soma das matrizes
*/
void sum(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

}

/**
*Metodo responsavel pela subtracao da matriz (m2-m1)
*/
void subtract(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            result[i][j] = m2[i][j] - m1[i][j];
        }
    }
}

/**
*Metodo responsavel adicionar uma constante as duas matrizes
*/
void constant(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            m1[i][j] = m1[i][j] * k;
            m2[i][j] = m2[i][j] * k;            
        }
    }
}

/**
*Metodo resposavel por realizar a multiplicacao das duas matrizes
*/
void multi(){
    int temp;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            result[i][j] = 0;
            for(int k = 0; k < 2; k++){
                result[i][j] += m1[i][k] * m2[k][j]; 
                //temp = temp + m1[i][k] * m2[k][j];
            }
            //result[i][j] = temp;
            //temp = 0;   
        }
    }    
}

/**
*Metodo responavel por receber a constante do user
*/
void getConstant(){
    printf("Digite a constante: ");
    scanf("%d", &k);
}

/**
*Metodo responsavel pela impressao da matriz resultado 
*@param x[n][n]
*/
void printResult(int x[n][n]){
    printf("Matriz resultante: \n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }
}

/**
*Metodo resposavel pela impressao dos valores atuais de cada matriz
*@param x[n][n]
*@param mat
 */
void printMat(int x[n][n], int mat){
    printf("Matriz %d: \n", mat);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }

}

/*
*Metodo auxiliar responsavel por zerar a matriz resultado */
void zer0(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            result[i][j] = 0;
        }
    }
}

/**
*Metodo responsvel por condicionar a operacao a ser realizada baseado na escolha do user
*/
void executeMenu(){
    switch(option){
        case 'A': case 'a':
        sum();
        break;

        case 'B': case 'b':
        subtract();
        break;

        case 'C': case 'c':
        getConstant();
        constant();
        zer0();
        break;

        case 'D': case 'd':
        multi();
        break;

        case 'E': case 'e':
        printMat(m1, 1);
        printMat(m2, 2);
        printResult(result);
        marcador++;
        break;

        case '!':
        printf("EXITING PROGRAM.............\n");
        break;

        default:
        printf("Digite um valor Valido!!!!!!!!!!!!!\n");
        break;
    }
}

int main(){

getElements(m1, 1);
getElements(m2, 2);
do{
    do{        
        menu();        
    }while(isInputCorrect());
    executeMenu();    
}while(option != '!');
return 0;
}