/************************************************************* 
*Nome:Marcos Cavalcante Barboza                              *
*R.A: 408.336                                                *
*Objetivo: Receber o tamanho de uma matriz quadrada e uma    *
*      string e preencher essa matriz com a string, e depois *  
*	   "decodificar" essa matriz e reescrevela.              *
*************************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#include <math.h>
#include <strings.h>
#define MAX 100


int main(){
char m[MAX][MAX],msg[MAX];
int num,pos=0,mat=0,i=0,c=0;

scanf("%d",&num); //le o tamanho da matriz

getchar();
scanf("%100[^\n]",msg); //le a string

mat = sqrt(num); //faz o calculo da raiz do tamanho da matriz, para deixar a matriz quadrada

for(i=0;i<mat;i++){
	for(c=0;c<mat;c++){
		m[i][c] = msg[pos]; // a matriz recebe cada caractere da string em cada coluna
		pos++;
	}
}

pos = 0;//zera o contador pos, para que ele possa ser usando da proxima vez

for(c=0;c<mat;c++){
	for(i=0;i<mat;i++){
		if(m[i][c] == '*'){ // desconsidera o caratere *
			msg[pos] = ' '; // "e no seu lugar preenche com o espaço"
			pos++;      
		}else{
			msg[pos] = m[i][c]; // a string recebe o caractere da matriz
			pos++;
		}
	}
}

//impressao da string

for(i=0;msg[i] != '\0';i++){
	printf("%c",msg[i]);
}
printf("\n");

return 0;
}
