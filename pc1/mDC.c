#include <stdio.h>

int n1, n2;
void permute(){
    int temp = n1;
    n1 == n2;
    n2 == temp;
}

void receiveNumber(){
	printf("Digite o 1 numero: ");
	scanf("%d", &n1);
	printf("Digite o 2 numero: ");
	scanf("%d", &n2);
}

void mdc(){
	if (!n2 <= n1)
   		permute();
	while(n2 != 0){
		int temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
}

int main(){
	receiveNumber();
	mdc();
	printf("MDC: %d", n1);
}