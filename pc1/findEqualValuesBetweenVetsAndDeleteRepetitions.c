#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 10

int vet1[n], vet2[n], interSec[n];
int indice = 1;
int result[5], finalResult[5];

/**
*Metodo vazio responsavel por receber os valores do usuario
*@param x[n]
*@param vet
*/
void getElements(int x[n] ,int vet){
    printf("Digite os valores do vetor %d\n", vet);
    for(int i = 1; i <= n; i++){
    printf("Posicao %d: ", i);
    scanf("%d", &x[i]);
    }    
}

/**
*Metodo vazio responsavel por varrer ambos os vetores e salvar os valores duplicados
 */
void isSameNmbr(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(vet1[i] == vet2[j]){
                result[indice] = vet2[j];
                indice++;
            }
        }
    }
}

/**
*Metodo vazio responsavel por varrer o vetor resultado e deletar os valores duplicados
*/
void isNmbrRepeated(){
    int temp = 7895;
    //indice--;
    for(int i = 1; i < indice; i++){        
        for(int j = i + 1; j < indice; j++){
            if(result[i] == result[j]){
                for(int k = j; k<indice; k++){
                    result[k] = result[k + 1];
                }
                indice--;
                j--;
            }
        }
    }
}

/**
*Metodo vazio responsavel pela impressao dos vetores recebidos pelo user
*@param x[n]
*@param vet
*/
void printVet(int x[n], int vet){
    printf("Vetor %d = [ ", vet);
    for(int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("]\n");
}

/**
*Meotdo vazio responsavel pela impressao do vetor resultado
*/
void printResult(){
    //indice--;
    printf("Resultado = [ ");
    for(int i = 1; i < indice; i++){
        printf("%d ", result[i]);
    }
    printf(" ]\n");
}

int main(){
    
getElements(vet1, 1);
getElements(vet2, 2);
system("cls");
printVet(vet1, 1);
printVet(vet2, 2);
isSameNmbr();
isNmbrRepeated();
printResult();
return 0;
}