/*
*****************************************************************
*Nome: Marcos Cavalcante Barboza                                *
*R.A: 408.336													*
*objetivo: construir um algoritmo que encontre o menor positivo *
*		   que pode ser divido por numeros de 1 a 20.			*
*****************************************************************
*/

//biblioteca utilizada
#include <stdio.h>

int main(){
int i=2520,k=1,div=0,flag=0;

for(i=2520;div != 10;i++){     // se div for diferente de 10 é porque o numero ja NAO foi encontrado, senao ele sai do for       
div = 0;
	for(k = 20;k >= 11;k--){       
		if((i % k) == 0){	 //   se o resto da divisao de i é o natural a ser verificado der 0, entao
			div ++;	//	  a variavel div(divisores) é incrementada
		}else{
			break;
		}
	}	
}   

printf("%d \n",i-1); // o numero i resultante da quebra da flag, é o numero procurado.

return 0;
}

