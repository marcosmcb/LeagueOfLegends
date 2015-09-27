/************************************************************* 
*Nome:Marcos Cavalcante Barboza                              *
*R.A: 408.336                                                *
*Objetivo: Receber uma data e retorna la por extenso, com o  *
*					dia da semana correspondente             *
*************************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#include<string.h>
#define TAM 15

enum Semana {dom,seg,ter,qua,qui,sex,sab}; //tipos enumerados dos dias da semana domigo = 0

enum Meses {jan=1,fev,mar,abr,mai,jun,jul,ago,set,out,nov,dez}; //tipos enumerados dos meses do ano com janeiro = 1

//prototipo das funcoes
void dia_do_ano(int dd, int mm, int aaaa);
void mes_do_ano(int mm);

int main(){
int day_unit=0,day_deze=0,year=0,unid=0,dezen=0,cent=0,milh=0;
char bar_1,bar_2,unidade[TAM],dezena[TAM],centena[TAM],milhar[TAM],dia_dez[TAM],dia_unit[TAM];

enum Meses month;

enum Semana day;

//leitura da data informada pelo usuario

scanf("%u",&day);
scanf("%c",&bar_1);
scanf("%u",&month);
scanf("%c",&bar_2);
scanf("%d",&year);


/******************VAI ESCREVER O DIA****************************/
/*
Bloco que recebe o dia informado pelo o usuario e o quebra nas pates unidade e dezena e 
escreve o dia corresponte a cada numero utilizando o switch

*/
day_unit = day%10;
switch(day_unit){
	case 1: strcpy(dia_unit,"e um");   break;
	case 2: strcpy(dia_unit,"e dois");   break;
	case 3: strcpy(dia_unit,"e tres");   break;
	case 4: strcpy(dia_unit,"e quatro");   break;
	case 5: strcpy(dia_unit,"e cinco");   break;
	case 6: strcpy(dia_unit,"e seis");   break;
	case 7: strcpy(dia_unit,"e sete");   break;
	case 8: strcpy(dia_unit,"e oito");   break;
	case 9: strcpy(dia_unit,"e nove");   break;
	default: strcpy(dia_unit,"");
}

day_deze = (day/10)%10;
switch(day_deze){
	case 1: 
		switch(day_unit){
			case 1: strcpy(dia_dez,"onze");      strcpy(dia_unit,"");  break;
			case 2: strcpy(dia_dez,"doze");      strcpy(dia_unit,"");  break;
			case 3: strcpy(dia_dez,"treze");     strcpy(dia_unit,"");  break;
			case 4: strcpy(dia_dez,"catorze");   strcpy(dia_unit,"");  break;
			case 5: strcpy(dia_dez,"quinze");    strcpy(dia_unit,"");  break;
			case 6: strcpy(dia_dez,"dezesseis"); strcpy(dia_unit,"");  break;
			case 7: strcpy(dia_dez,"dezessete"); strcpy(dia_unit,"");  break;
			case 8: strcpy(dia_dez,"dezoito");   strcpy(dia_unit,"");  break;
			case 9: strcpy(dia_dez,"dezenove");  strcpy(dia_unit,"");  break;
			default: strcpy(dia_dez,"dez");
		}; break;		
	case 2: strcpy(dia_dez,"vinte");   break;
	case 3: strcpy(dia_dez,"trinta");   break;
}

/***************************FIM*****************************/



/*****************VAI ESCREVER O ANO ***********************/
/*
Bloco que recebe o valor do ano e o quebra e 4 partes; unidade dezena centena e milhar
e escreve a frase correspondente ao valor de cada quebra
*/

unid = year%10;
switch(unid){
	case 1: strcpy(unidade,"e um");   break;
	case 2: strcpy(unidade,"e dois");   break;
	case 3: strcpy(unidade,"e tres");   break;
	case 4: strcpy(unidade,"e quatro");   break;
	case 5: strcpy(unidade,"e cinco");   break;
	case 6: strcpy(unidade,"e seis");   break;
	case 7: strcpy(unidade,"e sete");   break;
	case 8: strcpy(unidade,"e oito");   break;
	case 9: strcpy(unidade,"e nove");   break;
	default: strcpy(unidade,"");
}
dezen = (year/10)%10;
switch(dezen){
	case 1: 
		switch(unid){
			case 1: strcpy(dezena,"e onze");   
					strcpy(unidade,"");  break;
			case 2: strcpy(dezena,"e doze");   
					strcpy(unidade,"");  break;
			case 3: strcpy(dezena,"e treze");   
					strcpy(unidade,"");  break;
			case 4: strcpy(dezena,"e catorze");   
					strcpy(unidade,"");  break;
			case 5: strcpy(dezena,"e quinze");   
					strcpy(unidade,"");  break;
			case 6: strcpy(dezena,"e dezesseis");   
					strcpy(unidade,"");  break;
			case 7: strcpy(dezena,"e dezessete");   
					strcpy(unidade,"");  break;
			case 8: strcpy(dezena,"e dezoito");   
					strcpy(unidade,"");  break;
			case 9: strcpy(dezena,"e dezenove");   
					strcpy(unidade,"");  break;
			default: strcpy(dezena,"e dez");
		} break;
	case 2: strcpy(dezena,"e vinte");   break;
	case 3: strcpy(dezena,"e trinta");   break;
	case 4: strcpy(dezena,"e quarenta");   break;
	case 5: strcpy(dezena,"e cinquenta");   break;
	case 6: strcpy(dezena,"e sessenta");   break;
	case 7: strcpy(dezena,"e setenta");   break;
	case 8: strcpy(dezena,"e oitenta");   break;
	case 9: strcpy(dezena,"e noventa");   break;
	default: strcpy(dezena,"");
}

cent = ((year/10)/10)%10;
switch(cent){
	case 0: strcpy(centena," ");   break;
	case 9: strcpy(centena,"novencentos");   break;
}

milh = (((year/10)/10)/10)%10;
switch(milh){
	case 1: strcpy(milhar,"mil");   break;
	case 2: strcpy(milhar,"dois mil");   break;
}
/*****************FIM*************************************/


printf("\n\n");

//Impressao data por extenso
dia_do_ano(day,month,year);
printf(",%s %s de ",dia_dez,dia_unit);
mes_do_ano(month);
printf(" de %s %s %s %s \n",milhar,centena,dezena,unidade);


return 0;
}

/*funcao dia do ano realiza uma operacao que resulta no dia do ano
em determinada data*/

void dia_do_ano(int dd, int mm, int aaaa){
int a=0,y=0,m=0,q=0,d=0;

a = (14-mm)/12;
y = aaaa - a;
m = mm + 12*a - 2;
q = dd + (31*m)/12 + y + y/4 - y/100 + y/400;
d = q % 7;
//de acordo com o valor de d o retorno é 
switch (d){
		case dom:
			printf("Domingo"); break;	
		case seg:
			printf("Segunda-feira"); break;
		case ter:
			printf("Terça-feira"); break;
		case qua:
			printf("Quarta-feira"); break;
		case qui:
			printf("Quinta-feira"); break;
		case sex:
			printf("Sexta-feira"); break;
		case sab:
			printf("Sabado"); break;
	}

}

/*funcao mes_do_ano
de acordo com o mes do ano, é chamado um tipo enumerado correspondente ao ano
*/
void mes_do_ano(int mm){
switch (mm)
	{
		case jan:
			printf("Janeiro");break;	
		case fev:
			printf("Fevereiro");break;
		case mar:
			printf("Março");break;
		case abr:
			printf("Abril");break;
		case mai:
			printf("Maio");break;
		case jun:
			printf("Junho");break;
		case jul:
			printf("Julho");break;
		case ago:
			printf("Agosto");   break;
		case set:
			printf("Setembro"); break;
		case out:
			printf("Outubro");  break;
		case nov:
			printf("Novembro"); break;
		case dez:
			printf("Dezembro"); break;
	}
}

