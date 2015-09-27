/****************************************************************
*Nome:Marcos Cavalcante Barboza                                 *
*R.A: 408.336                                                   *
*Objetivo:  Encontrar o n-ésimo termo da funcao de              *
*		  fibonacci (utilizando função recursiva e ponteiros) e *
*		  retornar o seu valor, o algoritmo deve retornar       * 
*		  tambem a quantidade de recursoes realizadas.          *
****************************************************************/

#include <stdio.h>

//chamada da funcao
int fibo(int pos,int *recursoes); //utiliza ponteiro, para poder retornar a quantidade de recursoes realizadas

int main(){
int num,colocacao=0;//colocacao - variavel que indica o numero de recursoes relizadas no MAIN

do{

scanf("%d",&num);//o usuario informa o termo a ser calculado

}while(num < 1);

printf("elemento [%d] \n",fibo(num,&colocacao));//chamada da funcao fibonacci
printf("recursoes[%d] \n",colocacao); //impressao da quantidade de recursoes

return 0;
}

//funcao fibonacci
int fibo(int pos,int *recursoes){
*recursoes = *recursoes + 1;//incremento das recursoes realizadas
if ((pos == 1)||(pos == 2)){//o caso base da funcao de fibonacci recursiva é quando o termo  é 1 ou 2, e retorna o valor 1
	return 1;
}else{
	return fibo(pos - 1,recursoes) + fibo(pos - 2,recursoes); //calculo das posicoe
}

}


