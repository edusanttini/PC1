#include <stdio.h>
int atual, soma;
int maxComp, finalSum = 0;

void getSequence(){
    printf("Digite uma sequencia: \n");
    scanf("%d", &atual);
}
//Metodo para calcular a sequencia de maior comprimento decrescente e a soma do mesmo
void calcLengthAndSum(){
    int anterior;
    int comp = 0;
    soma = 0;
    if(!(atual == -1)){//Condicao de finalização da sequencia, caso o primeiro numero seja -1 
        comp = 1;
        maxComp = 1;
        anterior = atual;
        soma = atual;
        scanf("%d", &atual);//Recebe o segundo valor da sequencia
        do{//início do loop
            if(anterior > atual){//condicao de sequencias, se satisfeita, incrementa o comprimento e realiza a soma
                comp++;
                soma = soma + atual;                
            }            
            /*condicao para quebra de sequencia, so quebra quando possui maior comprimento, portanto,
            *em caso de mais de uma sequencia de mesmo comprimento, a soma será referente sempre referente a primeira sequencia.
            */
            else{
                if(comp > maxComp){//condicao de verificacao da sequencia de maior comprimento, caso exista uma quebra de sequencia
                    maxComp = comp;
                    finalSum = soma;
                }
                comp = 1;
                soma = atual;
            }
            anterior = atual;
            scanf("%d", &atual);//recebe os demais valores da sequencia
        }while(atual != -1);//condiciona ao loop, se satisfeito, retorna a linha 22
        if(comp > maxComp){//condicao de verificacao da sequencia de maior comprimento, caso nao exista uma quebra de sequencia
            maxComp = comp;
            finalSum = soma;
        }
    }
}

void printResult(){
    printf("Comprimento da maior sequencia decrescente: %d\n", maxComp);
    printf("SomaFinal: %d\n", finalSum);
}

int main(){    
    getSequence();
    calcLengthAndSum();
    printResult();    
   return 0;
}