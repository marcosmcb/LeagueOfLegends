/********************************************************************** 
*Nome:Marcos Cavalcante Barboza                                       *
*R.A: 408.336                                                         *
*Objetivo: Gerar UM MILHAO de numeros aleatorios e relaizar operacoes *
* tais como encontrar o maximo e minimo desses numeros e calcular     *
* a média e o desvio padrao, ordenar esses numeros e realizar dois    *
* tipos de busca nesse vetor,mostrando o tempo de execução            *
**********************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000000 

//prototipo das funcoes
void ordena(int ordena[],int ord);
int linear(int vlin[],int lin,int busca,double *timelin);
int binario (int vbin[], int bin,int opc,double *timebin);
int calculos(int num[],int tam,int *maiorp,int *minimop,float *desviop,float *mediop);

int main(){
int vet[MAX],i=0,opc=0,maximo=0,min=0;
float desv=0,media=0;
double tempobin=0,tempolin=0;

//planta semente 
srand(time(NULL));

//gera numeros aleatorios e armazena-os num vetor
for(i=0;i<MAX;i++){
	vet[i] = random()%MAX; 
}
//chamada das funcoes
	calculos(vet,MAX,&maximo,&min,&desv,&media);
	printf("ELEMENTO MAXIMO [%d] \n",maximo);
	printf("ELEMENTO MINIMO [%d] \n",min);
	printf("MEDIO   [%.2f] \n",media);
	printf("DESVIO PADRAO [%.2f] \n",desv);
	ordena(vet,MAX);
	printf("Informe o numero a ser procurado \n");
	scanf("%d",&opc);
	printf("Busca Binaria - O elemento [%d] esta na posicao  [-1] ---elemento nao encontrado: [%d] \n",opc,binario(vet,MAX,opc,&tempobin));
	printf("Tempo de duração Busca Linear= [%.3lf] milissegundos \n",tempolin);
	printf("Busca Linear - O elemento [%d] esta na posicao [-1] ---elemento nao encontrado: [%d] \n",opc,linear(vet,MAX,opc,&tempolin));
	printf("Tempo de duração Busca Binaria= [%.3lf] milissegundos \n",tempobin);
return 0;
}

int calculos(int num[],int tam,int *maiorp,int *minimop,float *desviop,float *mediop){
int i=0;
float soma=0,meio=0;
//utiliza ponteiro pois na devolucao, serao retornados varias variaveis

//busca o maior elemento de um vetor
	*maiorp = num[0];
	for(i=0;i<tam;i++){
		if(*maiorp < num[i]){
			*maiorp = num[i];
		}
	}

//busca o menor elemento do vetor
	*minimop = num[0]; 
	for(i=0;i<tam;i++){
		if(*minimop > num[i]){
			*minimop = num[i];
		}
	}

//calcula a media dos elementos do vetor
	for(i=0;i<tam;i++){
		*mediop = num[i] + *mediop;
	}
	*mediop = *mediop/tam;

//realiza o calculo do desvio padrao
	for(i=0;i<tam;i++){
		soma = num[i] * num[i] + soma;
	}
		meio = (*mediop * *mediop)/tam;	
		soma = (soma - meio)/tam-1;
		*desviop = sqrt(soma);
}


//chamada da funcao prototipo
int binario (int vbin[], int bin,int opc,double *timebin){
clock_t t0,tf;
double tempo_gasto;
t0=clock();
//realiza a busca binaria e devolve o tempo de execucao
int ini = 0, fim = bin - 1, meio = 0;
	while(ini <= fim){
		meio = (fim + ini)/2;
		if(opc == vbin[meio]){
			return meio;		
		}else if(opc > vbin[meio]){
				  ini = meio + 1;		
			  }else{
			      fim = meio - 1;		
			  }						
	}
	return -1;
	tf=clock();
	tempo_gasto=(double)(tf-t0)/(CLOCKS_PER_SEC/1000);
	*timebin = tempo_gasto;
}



int linear(int vlin[],int lin,int busca,double *timelin){
clock_t t0,tf;
double tempo_gasto;
t0=clock();
//realiza a busca linear e devolve o tempo de execucao
int i = 0;
	for(i=0;i<lin;i++){
		if(vlin[i] == busca){
			return i;
		}
	}
	return -1;
	tf=clock();
	tempo_gasto=(double)(tf-t0)/(CLOCKS_PER_SEC/1000);
	*timelin = tempo_gasto;

}


void ordena(int ordena[],int ord){
clock_t t0,tf;
double tempo_gasto;
t0=clock();
// realiza a ordenacao do vetor BubbleSort e retorna o tempo de execucao
int	bubble=0,auxiliar=0,count=0,k=0;
count = MAX - 1;
	while(count > 0){
		bubble = 0;	
		for(k=0;k < count;k++){
			if (ordena[k] >  ordena[k+1]){
				auxiliar = ordena[k];
				ordena[k] = ordena[k+1];
				ordena[k + 1] = auxiliar;
				bubble = k;
			}
		}
		count = bubble;
	}

	tf=clock();
	tempo_gasto=(double)(tf-t0)/(CLOCKS_PER_SEC/1000);
	printf("Tempo de duração Ordenacao = [%.3lf] milissegundos \n",tempo_gasto);	
}
