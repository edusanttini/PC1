#include<stdio.h>
 
int mat[6][6];
int row, col, sum = 0;

void getMatrixSize(){
    printf("Digite o tamanho de linhas: ");
    scanf("%d", &row);
    printf("Digite o tamanho de colunas: ");
    scanf("%d", &col);
}

void getMatrixValues(){
     printf("Entre com os elementos da matriz(%d,%d): \n", row, col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Posicao(%d,%d): ", i, j);
            scanf("%d",&mat[i][j]);
            if(i==j)
            {
                sum=sum+mat[i][j];
            }
        }
    }
}

void printMatrix(){
    printf("\nMatriz: \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void main(){
    getMatrixSize();
    getMatrixValues();
    printMatrix();
    printf("\nA soma da diagonal da matriz(%d,%d) eh: %d\n", row, col, sum);
}