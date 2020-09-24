#include <stdio.h>
int atual, soma;
int maxComp, finalSum = 0;

void getSequence(){
    printf("Digite uma sequencia: \n");
    scanf("%d", &atual);
}

//Method to calculate the longest decreasing sequency e its own sum
void calcLengthAndSum(){
    int anterior;
    int comp = 0;
    soma = 0;
    if(!(atual == -1)){ //Exit condition
        comp = 1;
        maxComp = 1;
        anterior = atual;
        soma = atual;
        scanf("%d", &atual);//Gets the sec value from the sequency
        do{
            if(anterior > atual){//Sequency condition, if satisfied, increases length and do the sum
                comp++;
                soma = soma + atual;                
            }            
            else{
                if(comp > maxComp){//longest sequency condition verify, in case there is a sequency brake
                    maxComp = comp;
                    finalSum = soma;
                }
                comp = 1;
                soma = atual;
            }
            anterior = atual;
            scanf("%d", &atual);
        }while(atual != -1);
        if(comp > maxComp){//longest sequency condition verify, in case there is not a sequency brake
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