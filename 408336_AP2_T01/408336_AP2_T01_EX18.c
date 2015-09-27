/************************************************************** 
*Nome:Marcos Cavalcante Barboza                               *
*R.A: 408.336                                                 *
*Objetivo: Ordenar os compromissos de uma pessoa		      *
**************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 100

//struct compromisso com os campos necessarios para insercao de um compromisso
struct Compromisso{
int dia;
char text[MAX];
};

typedef struct Compromisso comp;

//chamada da funcao de ordenacao de string
void Sort_String(comp eventos[],comp auxiliar,int count);

int main(){
int i=0,k=0,j=0,count=0,bubble=0;

	comp eventos[MAX];
	comp auxiliar;
//entrada de dados pelo usuario
do{

	printf("Informe o compromisso: \t");

	scanf("%d",&eventos[i].dia);
	printf("\t");

	if(eventos[i].dia != 0){
	//	getchar();	
		scanf("%100[^\n]",eventos[i].text);
	}

i++;
printf("\n");
}while(eventos[i-1].dia != 0);

count = i-2;
//ordenacao de compromissos por dia
while(count > 0){
	bubble=0;
	for(k=0;k < count;k++){
		if (eventos[k].dia >  eventos[k+1].dia){
			auxiliar = eventos[k];
			eventos[k] = eventos[k + 1];
			eventos[k + 1] = auxiliar;
			bubble = k;
		}
	}
count = bubble;
}

/*
for(k=0;k<i-1;k++){
	printf("%d    %s \n",eventos[k].dia,eventos[k].text);
}*/



Sort_String(eventos,auxiliar,count); 
printf(" \n");

printf("Dia  Compromisso \n");

for(k=0;k<i-1;k++){
	if(eventos[k].dia == 0){
		i=i+1;
	}
	printf("%d    %s \n",eventos[k].dia,eventos[k].text);
}



return 0;

}
//FUNCAO QUE ORDENA UMA STRING
void Sort_String(comp eventos[],comp auxiliar,int count){
int i,j;
	for(j=0; j<count; j++){
		for(i=0; i<count-1; i++){
			if(strcmp(eventos[i].text, eventos[i + 1].text) > 0){
				strcpy(auxiliar.text, eventos[i].text);
				strcpy(eventos[i].text, eventos[i + 1].text);
				strcpy(eventos[i].text, auxiliar.text);
			}
		}
	}
	
}

