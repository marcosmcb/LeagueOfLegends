/************************************************************* 
*Nome:Marcos Cavalcante Barboza                              *
*R.A: 408.336                                                *
*Objetivo: Em dado tempo de um jogo de damas, é perguntado as*
*		   peças pretas que podem realizar determinadas      *
*		   jogadas                                           *
*************************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#define MAX 8 

//prototipo da funcao
void move_peca_branca(int m[MAX][MAX],int tam);


int main(){
int j=0,i=0,k=0,d[MAX][MAX]={0},ppi[12],ppj[12],z=0;


//leitura do tabuleiro
for(i=0;i<MAX;i++){
	for(k=0;k<MAX;k++){
		scanf("%d",&d[i][k]);
	}
}
/*
FUNCAO tomar peças BRANCAS
Estratégia: se a matriz e md eterminada poiscao for = peça e preta e sua diagonal secundaria tiver uma peça BRANCA seguida de um espaço vazio,
a peça preta que pode realizar essa jogada é informada
*/

for(i=0;i<MAX;i++){
	for(j=0;j<MAX;j++){
		if (((d[i][j] == -1) && (d[i+1][j-1] == 1) && (d[i+2][j-2] == 0)) || ((d[i][j] == -1) && (d[i+1][j+1] == 1) && (d[i+2][j+2] == 0))){
			ppi[z] = i;
			ppj[z] = j;
			z++;
		}	
	}
}
z--;
printf("PODEM tomar peças Brancas: \n");

for(i=0;i<=z;i++){
	printf("[%d][%d] \n",ppi[i],ppj[i]);
}
//FIM da funcao peças BRANCAS

z=0;

/*FUNCAO "LIBERDADE de MOVIMENTOS"
funcao que verifica se uma determinada peça preta pode se movimentar no tabuleiro, vendo se nas "casas" das diagonais secundarias e primarias
existem peças que nao as travam, considerando assim somente os espaços vazios.
*/
for(i=0;i<MAX;i++){
	for(j=0;j<MAX;j++){
		if (((d[i][j] == -1) && (d[i+1][j-1] == 0)) || ((d[i][j] == -1) && (d[i+1][j+1] == 0))){
			ppi[z] = i;
			ppj[z] = j;
			z++;
		}	
	}
}

z--;

printf("LIBERDADE DE MOVIMENTOS: \n");

for(i=0;i<z;i++){
	printf("[%d][%d] \n",ppi[i],ppj[i]);
}
//FIM da funcao liberdade de movimentos;

z=0;

/*FUNCAO Bloqueado
funcao que verifica se determinada peça preta pode se mover nas diagonais secundarias e primarias, vendo se nao existe duas peças brancas consecautivas ou uma peça branca e uma preta, realizando todas as comparacoes necessarias.
*/
for(i=0;i<MAX;i++){
	for(j=0;j<MAX;j++){
		if (((d[i][j] == -1) && ((d[i+1][j-1] == 1)||(d[i+1][j-1] == -1)) && (d[i+2][j-2] != 0))  &&  ((d[i][j] == -1) && 
													((d[i+1][j+1] == 1) || ((d[i+1][j+1] == -1))) && ((d[i+2][j+2] != 0)))){
			ppi[z] = i;
			ppj[z] = j;
			z++;
		}	
	}
}
z--;
printf("NAO PODEM se mover: \n");

for(i=0;i<=z;i++){
	printf("[%d][%d] \n",ppi[i],ppj[i]);
}
//FIM da funcao bloqueado

return 0;
}




