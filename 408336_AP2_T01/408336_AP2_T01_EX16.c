/************************************************************** 
*Nome:Marcos Cavalcante Barboza                               *
*R.A: 408.336                                                 *
*Objetivo: Receber dados sobre bacias petroliferas e realizar *
*		   determinadas operacoes							  *
**************************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#define MAX 5

//struct com as informacoes da bacia
struct bacia{
int estoque;
int pesado;
int leve;
int renda;
};

typedef struct bacia petroleo;

//prototipo das funcoes

void bacia(petroleo pet[]);
void consumo(petroleo pet[]);
void venda(petroleo pet[]);
void fim_op(petroleo pet[]);
void atribui(petroleo pet[]);


int main(){
char opc,type;
int i = 0,flag=0,descob=0;
	petroleo pet[MAX];

//chamada da funcao atribui,que inicia as variaveis com os valores mencionados
atribui(pet);

//leitura da opcao do usuario
do{
	printf("Informe a opcao: \n");
	scanf("%c",&opc);
	//getchar();
	switch(opc){
		case 'd': //leitura sobre dados de descoberta de bacias
			do{
				printf("Informe a bacia \n");
				scanf("%d",&i);

			}while( (i >= 5) && (i < 0));
			
			do{		
					printf("Informe o tipo de petroleo [l] ou [p] \n");
					getchar();					
					scanf("%c",&type);
					if(type == 'p'){
						printf("Informe a quantidade desejada \n");
						scanf("%d",&descob);
						pet[i].pesado += descob;
						pet[i].estoque += descob;
						printf("\n");						
						printf("%d \t",i);
						printf("%d \t",pet[i].estoque);
						printf("%d \t",pet[i].pesado);
						printf("%d \t",pet[i].leve);
						printf("%d \t",pet[i].renda);
					}else if(type == 'l'){
						printf("Informe a quantidade desejada \n");
						scanf("%d",&descob);
						pet[i].leve += descob;
						pet[i].estoque += descob;
						printf("\n");
						printf("%d \t",i);
						printf("%d \t",pet[i].estoque);
						printf("%d \t",pet[i].pesado);
						printf("%d \t",pet[i].leve);
						printf("%d \t",pet[i].renda);
					}  

			}while((type != 'p') && (type != 'l'));  
			printf("\n");	
		
		
		break;

		case 'c':
			consumo(pet);	break; //funcao que realiza "subtrai" o consumo de determinada bacia
		case 'v':
			venda(pet);	break;  //funcao que realiza "subtrai" a venda de determinada bacia
		case 'f':
			fim_op(pet); // chamada da funcao fim das operacoes
			bacia(pet);	//chamada da funcao que imprime as bacias com maiores estoques e renda
			flag = 1;		break;
	}
getchar();
}while(flag != 1);

return 0;
}

//inicializa as variaveis
void atribui(petroleo pet[]){
int i=0;
	for(i=0;i<5;i++){
		pet[i].leve = 10;
		pet[i].pesado = 10;
		pet[i].estoque = 20;
		pet[i].renda = 0;
	}
}


//subtrai o consumo
void consumo(petroleo pet[]){
int consumo=0,num_bac=0;
char tipo;	

	printf("Informe a bacia de petroleo \n");
		scanf("%d",&num_bac);

	printf("Informe o tipo de petroleo \n");	
		getchar();		
		scanf("%c",&tipo);	

	printf("Informe a quantidade consumida \n");
	scanf("%d",&consumo);

	if (tipo == 'l'){
		if(consumo <= pet[num_bac].leve){
			pet[num_bac].leve = pet[num_bac].leve - consumo;
			pet[num_bac].estoque = pet[num_bac].estoque - consumo; 
			printf("%d \t",num_bac);
			printf("%d \t",pet[num_bac].estoque);
			printf("%d \t",pet[num_bac].pesado);
			printf("%d \t",pet[num_bac].leve);
			printf("%d \t",pet[num_bac].renda);
			printf("\n");
		}else{
			printf("----ERRO------quantidade consumida maior que disponivel-----------\n");	
		}
	}else if (tipo == 'p'){
		if(consumo <= pet[num_bac].pesado){
			pet[num_bac].pesado = pet[num_bac].pesado - consumo;
			pet[num_bac].estoque = pet[num_bac].estoque - consumo;
			printf("%d \t",num_bac);
			printf("%d \t",pet[num_bac].estoque);
			printf("%d \t",pet[num_bac].pesado);
			printf("%d \t",pet[num_bac].leve);
			printf("%d \t",pet[num_bac].renda);
			printf("\n");
		}else{
			printf("----ERRO------quantidade consumida maior que disponivel-----------\n");	
		}
	}



}


//subtrai a venda
void venda(petroleo pet[]){
int num_bac = -1,venda=0;
char tipo;

	printf("Informe a bacia de petroleo \n");		
	scanf("%d",&num_bac);

	printf("Informe o tipo de petroleo \n");	
		scanf("%c",&tipo);
		getchar();	 

	printf("Informe a quantidade vendida \n");
		scanf("%d",&venda);
	
	if(tipo == 'l'){
		if(venda <= pet[num_bac].leve){
			pet[num_bac].leve = pet[num_bac].leve - venda;
			pet[num_bac].estoque = pet[num_bac].estoque - venda;
			pet[num_bac].renda = 100*venda + pet[num_bac].renda;
			printf("%d \t",num_bac);
			printf("%d \t",pet[num_bac].estoque);
			printf("%d \t",pet[num_bac].pesado);
			printf("%d \t",pet[num_bac].leve);
			printf("%d \t",pet[num_bac].renda);
			printf("\n");
		}else{
			printf("--ERRO-------quantidade vendidad maior que disponivel-----------\n");	
		}
	}else{
		if(venda <= pet[num_bac].pesado){
			pet[num_bac].pesado = pet[num_bac].pesado - venda;
			pet[num_bac].estoque = pet[num_bac].estoque - venda;
			pet[num_bac].renda = 100*venda + pet[num_bac].renda;
			printf("%d \t",num_bac);
			printf("%d \t",pet[num_bac].estoque);
			printf("%d \t",pet[num_bac].pesado);
			printf("%d \t",pet[num_bac].leve);
			printf("%d \t",pet[num_bac].renda);
			printf("\n");
		}else{
			printf("--ERRO-------quantidade consumida maior que disponivel-----------\n");	
		}
	}
	
}





//imprime os dados de todas as bacias no fim das operacoes
void fim_op(petroleo pet[]){
int k=0;
	for(k=0;k<5;k++){
		printf("%d \t",k);
		printf("%d \t",pet[k].estoque);
		printf("%d \t",pet[k].pesado);
		printf("%d \t",pet[k].leve);
		printf("%d \t",pet[k].renda);
		printf("\n");	
	}
}

//imprime as bacias mais rentaveis e com maiores estoques
void bacia(petroleo pet[]){
int maior_renda[5],maior_estoque[5],i=0,k=0,z=0,maior_e,maior_r;
	
	maior_r = pet[0].renda;
	maior_e = pet[0].estoque;
	maior_renda[0] = 0;
	maior_estoque[0] = 0;
	

	for(i=0;i < 5;i++){

		if(maior_r < pet[i].renda){
			k=0;
			maior_r = pet[i].renda;
			maior_renda[k] = i;
		}else if(maior_r == pet[i].renda){
			k++;			
			maior_r = pet[i].renda;
			maior_renda[k] = i;
		}


		if(maior_e < pet[i].estoque){
			z=0;
			maior_e = pet[i].estoque;
			maior_estoque[z] = i;

		}else if(maior_e == pet[i].estoque){
			z++;			
			maior_e = pet[i].estoque;
			maior_estoque[z] = i;		
		}


	}
	printf("\n");

	for(i=0;i<z;i++){
		printf("%d (Bacia com maior estoque)",maior_estoque[i]);
		printf("\n");
	}
	for(i=0;i<k;i++){
		printf("%d (Bacia com maior renda)",maior_renda[i]);
		printf("\n");
	}








}
