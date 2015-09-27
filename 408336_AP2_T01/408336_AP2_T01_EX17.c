/********************************************************************** 
*Nome:Marcos Cavalcante Barboza                                       *
*R.A: 408.336                                                         *
*Objetivo: Cadastra Livros de acordo com autor,titulo e etc, e realiza* 
		   funcoes de calculo e busca							      *
**********************************************************************/

//bibliotecas utilizadas
#include <stdio.h>
#define MAX 1000

//struct livro
typedef struct Livro{
	int ano;
	char titulo[100];
	char autor[100];
	int nVolume; 		// Numero de exemplares de um dado livro.
	float preco;
} Livro;

//struct biblioteca
typedef struct Biblioteca{
	Livro V[MAX]; 	// Armazena a informa ̧ao de MAX livros
	int nLivros; 	// Numero de livros existentes na biblioteca.
}Biblioteca;


//chama dos prototipos da funcoes
Livro filllivro(Livro l1);
Biblioteca fillBiblioteca(Biblioteca b1, int numLivros);
int valorBiblioteca(Biblioteca b1);
int maiorBiblioteca(Biblioteca b1); 

int main(){
int i=0,maior=0,opc=0;
float valor=0;
	Biblioteca bccs;
	Livro l1;
	Livro l2;
	Biblioteca b1; 
	

				bccs = fillBiblioteca(bccs,5);	
				valor = valorBiblioteca(bccs);	
				printf("%.2f \n",valor);
				maior = maiorBiblioteca(bccs);
				printf("%s \n",bccs.V[maior].titulo);
				printf("\n"); 
			


return 0;
}

//funcao que realiza o cadastro dos campos do livro
Livro filllivro(Livro l1){

		printf("Ano do livro: \n");
		scanf("%d",&l1.ano);
		printf("Titulo do Livro: \n");
		getchar();
		scanf("%100[^\n]",l1.titulo);
		printf("Autor do Livro: \n");
		getchar();	
		scanf("%100[^\n]",l1.autor);
		getchar();
		printf("Volume do Livro: \n");
		scanf("%d",&l1.nVolume);
		printf("Preço do Livro: \n");
		scanf("%f",&l1.preco);
		printf("\n");

	return(l1);	
}


Biblioteca fillBiblioteca(Biblioteca b1, int numLivros){
int i=0;

b1.nLivros = numLivros;

	for(i=0;i < b1.nLivros;i++){
         b1.V[i] = filllivro(b1.V[i]);
	}

	return b1;

}

//funcao que realiza o calculo do preço do acervo da biblioteca
int valorBiblioteca(Biblioteca b1){
float mont=0;
int i=0;

	for(i=0;i < b1.nLivros;i++){
		mont = b1.V[i].nVolume * b1.V[i].preco + mont;
	}
	return mont;
}

//funcao que realiza a busca pelo livro de maior quantidade
int maiorBiblioteca(Biblioteca b1){
int maior=0, maior_pos=0,i=0;

	maior = b1.V[0].nVolume;
	maior_pos = 0;


	for(i=0;i<b1.nLivros;i++){
		if(maior < b1.V[i].nVolume){
			maior = b1.V[i].nVolume;
			maior_pos = i;
		}
	}
	return maior_pos;

}

