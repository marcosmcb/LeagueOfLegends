/*******************************************************
*Nome:Marcos Cavalcante Barboza                        *
*R.A: 408.336                                          *
*Objetivo: Encontrar o 10001º número primo             *
********************************************************/

#include <stdio.h>
#include <math.h>

int main(){
int div=0,n=1,i=0,k=0,j=0;


/*************************************************************************
*Função Primo: verifica se numeros maiores do que 2                      * 
* são primos, "pegando", somente os numeros impares                      * 
* (pois os pares tem como um dos divisores o 2), e calculando a sua      *
* raiz quadrada, pois existe um teorema que prova que um numero é primo  *
* se os nao existe divisores (com exceccao do 1),para numeros menores    *
* ou iguais que sua raiz quadrada.                                        *
*************************************************************************/

do{
	div = 1;               // a variavel div recebe 1, pois ja se considera q n é divisivel por n
	n = n + 2;            //procura somente entre os numeros impares
    j = sqrt(n);         //divide somente por numeros menores ou iguais que sua raiz
    for(i=1; i<=j; i++){ 
		if (div > 2){
           i = j+1; 
        }else{
           if ((n % i ) == 0){
                div = div + 1;
           }
        }
    }
    if (div == 2){
            k = k + 1;
        }
}while (k != 10000); // o laço é quebrado quando k = 10000, pois o 2 é "desconsiderado"

printf("%d \n", n);
return 0;
}
