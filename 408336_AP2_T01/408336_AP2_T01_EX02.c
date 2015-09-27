/*******************************************************
*Nome:Marcos Cavalcante Barboza                        *
*R.A: 408.336                                          *
*Objetivo: Realizar a busca de elementos minimo,maximo,*
*          soma,produto e media dos elementos de um    *
*		   vetor, utilizando função recursiva          *
********************************************************/

#include <stdio.h>
#define MAX 50 // constante com o tamanho máximo do vetor

//declaracao das funcoes do programa
int minimo(int vetor[],int my_tam);
int maximo(int vetor[],int my_tam);
int soma(int vetor[],int my_tam);
int produto(int vetor[],int my_tam);

int main(){
int tam=0,i,min=0,vet[MAX];

scanf("%d",&tam);   // lê o tam "tamanho" do vetor declarado pelo usuário

for(i=0;i<tam;i++){
	scanf("%d",&vet[i]); // lê o vetor informado pelo usuario 
}

printf("%d \n",minimo(vet,tam));
printf("%d \n",maximo(vet,tam));
printf("%d \n",soma(vet,tam));
printf("%d \n",produto(vet,tam));

/********************************************************************* 
* "Operação Média":                                                  *
* Nesse ponto, é realizada a média aritmética dos elementos do vetor,*
*"pegando" o return da funcao soma e o dividindo                     *
* por tam (tamanho do vetor).                                        *
*********************************************************************/
printf("%d \n",soma(vet,tam)/tam);

return 0;
}


/**********************************************************
*Função: Mínimo                                           *
*MÉTODO: É uma funcao recursiva que tem como caso base    *
*o tamanho do vetor = 0, e retorna para a funcao o        *
*valor do vetor quando ele tem tamanho 0, a variavel min, *
*recebe sempre o menor elemento da recursao, e o compara  *
*com os demais, se min for menor que a funcao, retorna    *
*min, senao retorna a funcao.                             *
**********************************************************/

int minimo(int vetor[],int my_tam){
int min=0;

if(my_tam == 0){
	return vetor[0];
}else{
	min = minimo(vetor,my_tam-1);
	if (min < vetor[my_tam -1]){
		 return min;
	}else{
		return vetor[my_tam-1];
	}
}
}

/**********************************************************
*Função: Máximo                                           *
*MÉTODO: É uma funcao recursiva que tem como caso base    *
*o tamanho do vetor = 0, e retorna para a funcao o        *
*valor do vetor quando ele tem tamanho 0, a variavel max, *
*recebe sempre o maior elemento da recursao, e o compara  *
*com os demais, se max for maior que a funcao, retorna    *
*max, senao retorna a funcao.                             *
**********************************************************/

int maximo(int vetor[],int my_tam){
int max=0;

if(my_tam == 0){
	return vetor[0];
}else{
	max = maximo(vetor,my_tam-1);
	if (max > vetor[my_tam -1]){
		 return max;
	}else{
		return vetor[my_tam-1];
	}
}
}

/***********************************************************
*Função: Soma                                              *
*MÉTODO: É uma funcao recursiva que tem como caso base     *
*o tamanho do vetor = 0, e retorna para a funcao o         *
*valor do vetor quando ele tem tamanho 0, ela soma o vetor * 
*com  tamanho maximo + a funcao soma.                      *
***********************************************************/

int soma(int vetor[],int my_tam){
if(my_tam == 1){
	return vetor[0];
}else{
	return (vetor[my_tam -1] + soma(vetor,my_tam-1));
}
}

/***********************************************************
*Função: Produto                                           *
*MÉTODO: É uma funcao recursiva que tem como caso base     *
*o tamanho do vetor = 0, e retorna para a funcao o         *
*valor do vetor quando ele tem tamanho 0, ela multiplica   * 
*o vetor com  tamanho maximo  pela funcao produto.         *
***********************************************************/

int produto(int vetor[],int my_tam){
if(my_tam == 0){
	return vetor[0];
}else{
	return (vetor[my_tam -1] * produto(vetor,my_tam-1));
}
}
