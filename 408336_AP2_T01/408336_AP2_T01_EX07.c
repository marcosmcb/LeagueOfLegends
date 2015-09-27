/*******************************************************
*Nome:Marcos Cavalcante Barboza                        *
*R.A: 408.336                                          *
*Objetivo: Realizar 3 operacoes com 3 funcoes,		   *  
*		   utilizando recursividade				       *
*******************************************************/

#include <stdio.h>

//prototipo da funcoes
int sequenciaA(int n); 
int sequenciaB(int n);
int sequenciaC(int n);


int main(){
int num;

scanf("%d",&num); // o usuario informa o termo da funcao que ele quer e é calculado o termo equivalente em cada funcao
//chamada das funcoes
printf("%d \n", sequenciaA(num));
printf("%d \n", sequenciaB(num));
printf("%d \n", sequenciaC(num));

return 0;
}

int sequenciaA(int n){

if(n == 1){
	return 10;
}else{
	return (sequenciaA(n-1) + 10);//volta atraves da recursao para o caso base 1 e retorna o valor 10,realizando as operacoes necessarias ate o termo pedido
}
}

int sequenciaB(int n){

if(n == 1){
	return 1;
}else{
	return (sequenciaB(n-1) + n*n); // volta para o caso base 1 e retorna 1,, realizando as operacoes necessarias ate o termo pedido
}
}

int sequenciaC(int n){

if(n == 1){
	return 1;
}else{
	return (sequenciaC(n-1) + 3);	//volta para o caso base 1 e retorna 1, realizando as operacoes necessarias ate o termo pedido
}
}
