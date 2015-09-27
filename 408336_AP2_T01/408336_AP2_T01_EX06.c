/*******************************************************
*Nome:Marcos Cavalcante Barboza                        *
*R.A: 408.336                                          *
*Objetivo: Encontrar o ponto de sela de uma matriz	   *
*******************************************************/

#include <stdio.h>
#define MAX 50

//funcao prototipo
void psela(int sela[][MAX],int tamanho);
int main(){
int m[MAX][MAX]={},i=0,j=0,tam=0;

//leitura do tamanho da matriz
do{

scanf("%d",&tam);

}while(tam > 50);

//leitura da matriz
for(i=0;i<tam;i++){
	for(j=0;j<tam;j++){
		scanf("%d",&m[i][j]);
	}
}
//chamada da funcao psela para impressao do ponto de sela
psela(m,tam);

return 0;
}

//funcao psela encontra o ponto de sela de uma matriz realizando comparacoes entre o maior elemento da linha e menor da coluna e vice-versa
void psela(int sela[][MAX],int tamanho){
int min[3],j=0,k=0,sel=0,flag=0,z=0,i=0,ponto=0;



for(i=0;i<tamanho;i++){
	for(j=0;j<tamanho;j++){
		ponto = sela[i][j];	
		for(k=0;k<tamanho;k++){	
			for(z=0;z<tamanho;z++){
				if(((ponto > sela[z][k]) && (ponto < sela[k][z])) || ((ponto < sela[k][z]) && (ponto > sela[z][k]))){
					min[0] = i;
					min[1] = j;
					min[2] = sela[i][j];
					flag = 1;
					z=tamanho;
					k=tamanho;
					j=tamanho;
					i=tamanho;
				}	
			}
		}		
	}
}

if(flag == 1){
	printf("Existe ponto de sela !!!\n");	
	printf("ponto de sela: [%d] [%d], valor do ponto: [%d] \n",min[0],min[1],min[2]);
}else{
	printf("Não existe ponto de sela \n");
}

}
