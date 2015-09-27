/*******************************************************
*Nome:Marcos Cavalcante Barboza                        *
*R.A: 408.336                                          *
*Objetivo: Analisar as relacoes de intersecção,contido,*
*          e subtracao entre dois conjuntos A,B.       *
*******************************************************/

// bibliotecas utilizadas pelo sistema
#include <stdio.h>
#define MAX 50 // constante que representa o tamanho maximo do vetor

//Protótipo das funcoes a serem utilizadas.
void interseccao (int va[],int vb[],int a1,int b1); 
void subtracao (int va[],int vb[],int a1,int b1);
int contido(int va[],int vb[],int a1,int b1);


int main(){
int ca[MAX],cb[MAX]={0},a=0,b=0,i=0,opc=0;

do{
	scanf("%d",&a);    // Leitura do tamanho do conjunto A, e verificação do intervalo permitido.
}while((a<0) || (a>MAX));

for(i=0;i < a;i++){
	scanf("%d",&ca[i]);
}

do{
	scanf("%d",&b);   // Leitura do tamanho do conjunto B, e verificação do intervalo permitido.
}while((b<0) || (b>MAX));

for(i=0;i < b;i++){
	scanf("%d",&cb[i]);
}

do{
scanf("%d",&opc); // Leitura da opção de Consulta a ser feita pelo usuario
switch(opc){
	case 1: 
		printf("INTERSECCAO \n");
		interseccao(ca,cb,a,b);	break;
	case 2: 
		printf("SUBTRACAO \n");
		subtracao (ca,cb,a,b); break;
	case 3: 
		printf("CONTIDO \n");
		printf("%d \n",contido (ca,cb,a,b)); break;
	case 4: 
		opc = 4;
	break;
	default:
	printf("Opcao invalida \n");
}
}while(opc != 4);


return 0;
}

/*
******************************************************************************
*Funcao Interseccao:                                                         *
*Percorre o vetor A,pegando o primeiro elemento e depois os susequentes,     *
*e entra percorrendo o vetor B, verifica se o elemento do vetor A esta em B  *
*Se existir elemento comum de A em B, esse elemento é armazenado em um outro *
*vetor, vetor interseccao.                                                   *
******************************************************************************
*/

void interseccao (int va[],int vb[],int a1,int b1){
int i, vc[a1],z=0,k,flag=0;

for(k=0;k < a1;k++){           
	for(i=0;i < b1;i++){     
		if(va[k] == vb[i]){   
			flag = 1;		 //	  FLAG de verificacao se o conjunto é vazio
			vc[z] = va[k];
			z++;    
			i = b1;
		}
	}	
}

z--; //z é decrementado pois foi incrementado apos o preenchimento do ultimo elemento do vetor

if(flag == 0){      //Se a FLAG permanecer setada com 0, entao o conjunto é vazio
	printf("vazio \n");
}else{               
	for(i=0;i <= z;i++){
		printf("%d \n",vc[i]); 
	}
}
}

/*
**********************************************************************************
*Funcao Subtracao:                                                               *
*Percorre o vetor A,pegando o primeiro elemento e depois os susequentes,         *
*e entra percorrendo o vetor B, verifica se o elemento do vetor A esta em B      *
*Se existir elemento igual de A em B, esse elemento é desconsiderado e o laço é  *
*quebrado,se for diferente, entao o elemento do vetor A é armazenado no vetor    * *subtracao.                                                                      *
**********************************************************************************
*/

void subtracao (int va[],int vb[],int a1,int b1){
int i,k,z=0,f=0,vc[a1],flag=0;

for(i=0;i < a1;i++){               
	for(k=0;k < b1;k++){
		if(va[i] == vb[k]){ 
		   f = 1;
		   break;
		}		
	} 
	if(f == 0){
		flag = 1;     //FLAG que diz a respeito do estado do Conjunto "cheio" = 1
		vc[z] = va[i];
		z++;	
	}
	f = 0;
}

z--; //z é decrementado pois foi incrementado apos o preenchimento do ultimo elemento do vetor

if(flag == 0){    //FLAG que diz a respeito do estado do conjunto "vazio" = 0
	printf("vazio");
}else{
	for(i=0;i <= z;i++){
		printf("%d \n",vc[i]);
	}
}
}

/*
******************************************************************************
*Funcao Contido:   															 *                                                           
*Se o conjunto A for maior do que B, entao nao sao subconjuntos proprios e   *
*retorna 0 (FALSO).															 *
*Percorre o vetor A,pegando o primeiro elemento e depois os subsequentes,    *
*e entra percorrendo o vetor B, verifica se o elemento do vetor A esta em B  *
*Se todos os elemento de A estiverem em B e o conjunto A for menor do que B, *
*entao retorna 1(VERDADEIRO).												 *
*E se o conjunto A for do mesmo tamanho do de B, e todos os elementos forem  *
*iguais, entao retorna 0(FALSO).						                     *
******************************************************************************
*/

int contido(int va[],int vb[],int a1,int b1){
int i,k,z=0,f=1;
if (a1 > b1){
	return 0;	
}else if(a1 < b1){
	for(i=0;i < a1;i++){
		for(k=0;k < b1;k++){
			if(va[i] == vb[k]){
			  f = 0;      //FLAG que verifica se os elementos de A estao em B   
			}
		}
		if(f == 0){      
			f = 1;
		}else{			//se os elementos nao estiverem, a FLAG tem valor 1 e retorna 0 (FALSO)
			f = 0;
			return f;				
		}
	}
}else if ((a1==b1) && (f == 1)){
	f = 0;
}
return f;
}
