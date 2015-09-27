/********************************************************
*Nome:Marcos Cavalcante Barboza                         *
*R.A: 408.336                                           *
*Objetivo: Realizar o cadastro de alunos usando structs *
********************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//struct que "carrega o endereço"
struct local{
	char rua[MAX];
	char cidade[MAX];
	char estado[MAX];
	int cep;
};

typedef struct local Elocal;

//struct que "carrega a data de nascimento"
struct tempo{
	int dia;
	int mes;
	int ano;
};

typedef struct tempo Data;

//struct que carrega os dados do aluno
struct estudante{
	char nome[MAX];
	Data datanasc;
	int rg;
	Elocal ender;
	char sexo[MAX];
	int ra;
	float ira;
};

typedef struct estudante pessoa;


//prototipos das funcoes
void ira_b(pessoa aluno[],int count);
void idade_c(pessoa aluno[],int count,int tam);
void ra_d(pessoa aluno[],int count,int ler);
void ficha_e(pessoa aluno[],int count);

int main(){
int opc=0,count=0,ler_ra=0;
	pessoa aluno[MAX];



/*
Menu de leitura de opcoes para o usuario
*/

do{
	printf("Escolha uma opcao[1...6] \n");
	scanf("%d",&opc);

	switch(opc){
		case 1: //opcao que realiza o cadastro de novos estudantes
			if(count < MAX){
				getchar();				
				printf("Informe o nome: \n");					
				scanf("%40[^\n]",aluno[count].nome);
				printf("Informe o dia de nascimento \n");
				scanf("%d",&aluno[count].datanasc.dia);
				printf("Informe o mes [1..12] de nascimento \n");
				scanf("%d",&aluno[count].datanasc.mes);
				printf("Informe o ano de nascimento \n");
				scanf("%d",&aluno[count].datanasc.ano);
				printf("Informe o numero do rg \n");
				scanf("%d",&aluno[count].rg);
				getchar();
				printf("Informe o sexo [MASCULINO] ou [FEMININO] \n");
				scanf("%40[^\n]",aluno[count].sexo);
				getchar();
				printf("Informe a rua \n");
				scanf("%40[^\n]",aluno[count].ender.rua);
				getchar();
				printf("Informe a cidade \n");
				scanf("%40[^\n]",aluno[count].ender.cidade);
				getchar();
				printf("Informe o estado \n");
				scanf("%40[^\n]",aluno[count].ender.estado);
				printf("Informe o cep \n");	
				scanf("%d",&aluno[count].ender.cep);
				printf("Informe o numero do ra \n");
				scanf("%d",&aluno[count].ra);
	
			do{
					printf("Informe o valor do ira \n");
					scanf("%f",&aluno[count].ira);

			}while((aluno[count].ira < 0)||(aluno[count].ira > 1)); //se o r.a nao estiver no intervalo[0..1], o pedido é feito novamente

		}else{
			printf("Memoria Insuficiente \n"); //se o total de estudantes cadastrados execeder o numero limite a mensagem é mostrada
		}

		count++; //contador de estudantes
		break;

		case 2:
			ira_b(aluno,count); break; //funcao que exibe o maior e menor ira
		case 3:
			idade_c(aluno,count,MAX); break; //funcao que exibe o aluno mais velho
		case 4:
			printf("Informe o r.a \n"); //o usuario informa o r.a
			scanf("%d",&ler_ra); // e os dados do aluno sao mostrados na tela
			ra_d(aluno,count,ler_ra); break;
		case 5:
			ficha_e(aluno,count); break; //funcao que mostra todos os alunos cadastrados na ordem em que foram inseridos
		case 6:
			opc = 6; break;
		default:
			printf("Escolha outra opcao \n");
	}
}while(opc != 6);

return 0;
}

void ira_b(pessoa aluno[],int count){
int k=0,n=0;
float maior=0,menor=0;

	maior = aluno[0].ira;
	menor = aluno[0].ira;

//verificacao do maior e menor ira
for(k=0;k < count;k++){
	if(maior < aluno[k].ira){
		maior = aluno[k].ira;
	}else if(menor > aluno[k].ira){
		menor = aluno[k].ira;	
	}
}

printf("Maior IRA: [%f] \n",maior);
printf("Menor IRA: [%f] \n",menor);

}

void idade_c(pessoa aluno[],int count,int tam){
int k=0,ano_novo=0,ano_velho=0,mes_novo=0,mes_velho=0,dia_novo=0,dia_velho=0;
	
	ano_novo = aluno[0].datanasc.ano;
	mes_novo = aluno[0].datanasc.mes;
	dia_novo = aluno[0].datanasc.dia;
	ano_velho = aluno[0].datanasc.ano;
	mes_velho = aluno[0].datanasc.mes;
	dia_velho = aluno[0].datanasc.dia;


/*
Bloco da funcao que encontra o aluno mais novo
*/

for(k=0;k < count;k++){
	if ((aluno[k].datanasc.ano) > ano_novo){ //realiza a comparacao inicialmente por ano de nascimento
		ano_novo = aluno[k].datanasc.ano;
		mes_novo = aluno[k].datanasc.mes;
		dia_novo = aluno[k].datanasc.dia;
	}else if ((aluno[k].datanasc.ano) ==  ano_novo){ // se os anos de nascimento forem iguais,
		if ((aluno[k].datanasc.mes) > mes_novo){ //é relizada a comparacao por mes
			ano_novo = aluno[k].datanasc.ano;
			mes_novo = aluno[k].datanasc.mes;
			dia_novo = aluno[k].datanasc.dia;		
		}else if ((aluno[k].datanasc.mes) == mes_novo){ // se os meses forem iguais,
			if ((aluno[k].datanasc.dia) > mes_novo){// a comparacao é feita pelo dia de nascimento
				ano_novo = aluno[k].datanasc.ano;
				mes_novo = aluno[k].datanasc.mes;
				dia_novo = aluno[k].datanasc.dia;
			}
		}
	}   


/*
Bloco da funcao que encontra o aluno mais velho
*/
//funcao de busca semelhante a do aluno mais novo 


	if ((aluno[k].datanasc.ano) < ano_velho){
		ano_velho = aluno[k].datanasc.ano;
		mes_velho = aluno[k].datanasc.mes;
		dia_velho = aluno[k].datanasc.dia;
	}else if ((aluno[k].datanasc.ano) ==  ano_velho){
		if ((aluno[k].datanasc.mes) < mes_velho){
			ano_velho = aluno[k].datanasc.ano;
			mes_velho = aluno[k].datanasc.mes;
			dia_velho = aluno[k].datanasc.dia;		
		}else if ((aluno[k].datanasc.mes) == mes_velho){
			if ((aluno[k].datanasc.dia) < dia_velho){
				ano_velho = aluno[k].datanasc.ano;
				mes_velho = aluno[k].datanasc.mes;
				dia_velho = aluno[k].datanasc.dia;
			}
		}
	}  
		
		

}		

for(k=0;k<count;k++){
	if((ano_novo == aluno[k].datanasc.ano) && (mes_novo == aluno[k].datanasc.mes) && (dia_novo = aluno[k].datanasc.dia)){
		printf("Aluno mais novo: [%s] \n",aluno[k].nome);
	}
	if((ano_velho == aluno[k].datanasc.ano) && (mes_velho == aluno[k].datanasc.mes) && (dia_velho = aluno[k].datanasc.dia)){
		printf("Aluno mais velho: [%s] \n",aluno[k].nome);
	}

}


}


void ra_d(pessoa aluno[],int count,int ler){
int k=0,busca_ra = 0;
//busca linear do r.a.
for(k=0;k<count;k++){
	if(ler == aluno[k].ra){
		busca_ra = 1;		
		printf("funcao R.A. \n");
		puts(aluno[k].nome);
		printf("%d \n",aluno[k].datanasc.dia);
		printf("%d \n",aluno[k].datanasc.mes);
		printf("%d \n",aluno[k].datanasc.ano);
		printf("%d \n",aluno[k].rg);
		printf("%s \n",aluno[k].sexo);
		puts(aluno[k].ender.rua);
		puts(aluno[k].ender.cidade);
		puts(aluno[k].ender.estado);	
		printf("%d \n",aluno[k].ender.cep);
		printf("%d \n",aluno[k].ra);
		printf("%f \n",aluno[k].ira);
	}
}
	if(busca_ra == 0){
		printf("Aluno nao cadastrado \n"); // se o ra nao foi encontrado a mensagem sera exibida			
	}

}
void ficha_e(pessoa aluno[],int count){
int k=0;
printf("FUNCAO FICHA \n");

//impressao das fichas do aluno

for(k=0;k < count;k++){
	printf("Aluno [%d]\n",k+1);
	printf("%s \n",aluno[k].nome);
	printf("%d \n",aluno[k].datanasc.dia);
	printf("%d \n",aluno[k].datanasc.mes);
	printf("%d \n",aluno[k].datanasc.ano);
	printf("%d \n",aluno[k].rg);
	printf("%s \n",aluno[k].sexo);
	printf("%s \n",aluno[k].ender.rua);
	printf("%s \n",aluno[k].ender.cidade);
	printf("%s \n",aluno[k].ender.estado);	
	printf("%d \n",aluno[k].ender.cep);
	printf("%d \n",aluno[k].ra);
	printf("%f \n",aluno[k].ira);
}
printf("\n");
}

