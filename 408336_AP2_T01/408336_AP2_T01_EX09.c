/************************************************************* 
*Nome:Marcos Cavalcante Barboza                              *
*R.A: 408.336                                                *
*Objetivo:Algoritmo que verifica se uma matriz é do tipo     * 
*		  "Quadrado magico".						             *
*************************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#include <stdbool.h>
#define MAX 50 

//declaracao do prototipo das funcoes
bool somalinhas(int mr[][MAX],int tam);
bool somacolunas(int mr[][MAX],int tam); 
int diagpri(int mr[][MAX],int tam);
int diagsec(int mr[][MAX],int tam);

int main(){
int num=0,i=0,k=0,m[MAX][MAX] = {0};
bool check = true,chk = true;

scanf("%d",&num); // leitura das dimensoes da matriz

// leitura da matriz
for(i=0;i<num;i++){
	for(k=0;k<num;k++){   
		scanf("%d",&m[i][k]);
	}
}

//chamada e verificacao booleana das funcoes somalinhas e somacolunas
if ((somalinhas(m,num) && somacolunas(m,num)) == false){
	chk = false;
}

//chamada e verificacao booleana das funcoes diagonalprimaria e diagonalsecundaria
if (diagpri(m,num) != diagsec(m,num)){
	check = false;
}

//se as variaveis boolenas das duas verifcacoes anteriores forem falsas
if((chk && check) == false){
	printf("NAO e quadrado magico \n"); //retorna que é nao é quadrado magico
}else{
	printf("Quadrado Magico \n"); //senao qretorna que é quadrado magico
}

return 0;
}


/*funcao booleana somalinhas
realiza a soma de cada linha da matriz e a armazena num vetor
e depois realiza a busca linear dos elementos desse vetor para verificar se todos sao iguais
se forem a variavel booleana recebe true senao recebe false
*/
bool somalinhas(int mr[][MAX],int tam){
bool verifica = true;
int i=0,k=0,sl[tam],count=0;

for(i=0;i<tam;i++){
	sl[i] = 0;
	for(k=0;k<tam;k++){
		sl[i] = mr[i][k] + sl[i];
	}
}
count = sl[0];

for(k=0;k<i;k++){
	if(count != sl[k]){
		verifica = false;
	}
}

return (verifica);
}

/*funcao booleana somacolunas
realiza a soma de cada coluna da matriz e a armazena num vetor
e depois realiza a busca linear dos elementos desse vetor para verificar se todos sao iguais
se forem a variavel booleana recebe true senao recebe false
*/
bool somacolunas(int mr[][MAX],int tam){
bool verifica = true;
int i=0,k=0,sc[tam],count=0;

for(i=0;i<tam;i++){
	sc[i] = 0;
	for(k=0;k<tam;k++){
		sc[i] = mr[k][i] + sc[i];
	}
}
count = sc[0];

for(k=0;k<i;k++){
	if(count != sc[k]){
		verifica = false;
	}
}

return (verifica);
}

/*funcao diagpri
soma todos os elementos da diagonal primaria e retorna o valor dessa soma
*/
int diagpri(int mr[][MAX],int tam){

int pri=0,i=0,k=0;
for(i=0;i<tam;i++){
	for(k=0;k<tam;k++){
		if(i == k){
			pri = pri + mr[i][k]; 
		}
	}
}
return (pri);
}

/*funcao diagsec
soma todos os elementos da diagonal secundaria e retorna o valor dessa soma
*/

int diagsec(int mr[][MAX],int tam){
int sec=0,i=0,k=0;

for(k=tam-1;k >= 0;k--){
	sec = sec + mr[i][k];
	i++;
}
return (sec);
}
