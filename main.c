/*******************************************
Trabalho 1 - Estrutura de Dados 2
            INDEXAÇÃO
Prof. Tiago A. Almeida
Autores:
        Marcos Cavalvante
        Yanick Oliveira Rossi 408646
        
                        MENU
1-Cadastro    
2-Alteração
3-Remoção
4-Busca
            1. por código
            2.por nome da equipe vencedora
            3. por apelido do MVP
5-Listagem
            1. por código(ordem lexicográfica)
            2. por nome da equipe vencedora(ordem lexicográfica)
            3. por apelido do MVP(ordem lexicográfica)
            
6-Liberar Espaço
7-Finalizar
Implementação
Implementar uma biblioteca de manipulaçãp de arquivos para o seu programa, contendo obriga-
toriamente as seguintes funcionalidades:
• Uma estrutura de dados para armazenar os  ́ındices na meḿoria principal;
• Verificar se o arquivo de dados existe;
• Verificar se o  ́ındice priḿario existe;
• Verificar se os  ́ındices secund́arios existem;
• Criar o  ́ındice priḿario: deve refazer o  ́ındice prim ́ario a partir do arquivo de dados e substituir,
caso haja, o  ́ındice existente no disco;
• Criar os  ́ındices secund́arios: deve refazer os  ́ındices secud ́arios a partir do arquivo de dados
e substituir, caso haja, os  ́ındices existentes no disco;
• Carregar os  ́ındices do disco para a meḿoria principal;
• Inserir um registro: modificando o arquivo de dados no disco, e os  ́ındices na meḿoria principal.
• Buscar por registros: busca pela chave priḿaria ou por uma das chaves secund́arias.
• Alterar um registro: modificando o arquivo de dados no disco.
• Remover um registro: modificando o arquivo de dados no disco e o  ́ındice priḿario na meḿoria
principal.
• Listar registros: listar todos os registros ordenados pela chave priḿaria ou por uma das chaves
secund́arias.
• Liberar espa̧co: removendo fisicamente do arquivo de dados todos os registros marcados como
excluıdos, e atualizando os  ́ındices.
• Atualizar todos os  ́ındices: dever ́a ser chamada ao finalizar o programa e dever ́a gravar os
arquivos de  ́ındices no disco a partir das estruturas da memória principal
********************************************/


<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428

#define DADOS_FILE "teste.dat"
#define PRIMARY_FILE "iprimary.idx"
#define WINNER_FILE "iwinner.idx"
#define MVP_FILE "imvp.idx"
#define MAX_REGISTRO 192
<<<<<<< HEAD
#define MAX_INDICE 50
=======
>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428

typedef struct _matche{
    
    char codigo[9];
    char equipeAzul[39];
    char equipeVermelha[39];
    char data[11];
    char duracao[6];
    char equipeVencedora[39];
    char placarAzul[3];
    char placarVermelha[3];
    char apelidoMVP[39];

}MATCHE;
typedef struct _iprimary{
	char codigo[9];
	int rrn;
}IPRIMARY;

typedef struct _iwinner{
	char iEquipeVencedora[39];
	char codigo[9];
}IWINNER;

typedef struct _imvp{
	char iMVP[39];
	char codigo[9];

}IMVP;

<<<<<<< HEAD
//int buscarCodigoIndicePrimario();
/*
void ordenarIndicePrimario();
void ordenarIndiceWinner();
void ordenarIndiceMVP();
*/

int buscarCodigoIndicePrimario(IPRIMARY *listaIndicePrimario, int totalRegistros, char *codigo);

void cadastrarRegistro(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, IWINNER **listaIndiceWinner, int *totalRegistros);

void carregarIndicePrimario(IPRIMARY **listaIndicePrimario, int *totalRegistros);
void carregarIndiceMVP(IMVP **listaIndiceMVP, int *totalRegistros);
void carregarIndiceWinner(IWINNER **listaIndiceWinner, int *totalRegistros);

int compararIndicePrimario(const void *str1, const void *str2);
int compararIndiceMVP(const void *str1, const void *str2);
int compararIndiceWinner(const void *str1, const void *str2);

void imprimirBuscaCodigo(int rrnCodigo, char *codigo);

void listarPorCodigo(IPRIMARY **listaIndicePrimario, int *totalRegistros);
void listarPorMVP(IMVP **listaIndiceMVP, int *totalRegistros);
void listarPorWinner (IWINNER **listaIndiceWinner, int *totalRegistros);

void ordenarIndicePrimario(IPRIMARY **listaIndicePrimario, int totalRegistros);
void ordenarIndiceMVP(IMVP **listaIndiceMVP, int totalRegistros);
void ordenarIndiceWinner(IWINNER **listaIndiceWinner, int totalRegistros);

int main(void){
	int opcMenu, opcSubMenu, totalRegistros;
    int resultadoBuscaCodigo;
    char strBuscaCodigo[39];
	FILE *dataFile;
    IPRIMARY *listaIndicePrimario = NULL;
    IWINNER *listaIndiceWinner = NULL;
    IMVP *listaIndiceMVP = NULL;


    dataFile = fopen(DADOS_FILE,"a");
    totalRegistros = (int) ( ftell(dataFile) / MAX_REGISTRO );
    //printf("Valor de FTELL [%d]\n", ftell(dataFile) );
    fclose(dataFile);

    carregarIndicePrimario(&listaIndicePrimario, &totalRegistros);
    carregarIndiceMVP(&listaIndiceMVP, &totalRegistros);
    carregarIndiceWinner(&listaIndiceWinner, &totalRegistros);

    

    do{ 
        scanf("%d", &opcMenu);
        printf("Valor Menu [%d] \n", opcMenu);
        
        switch(opcMenu){
            case 1:     
                //cadastrar;
                cadastrarRegistro(&listaIndicePrimario, &listaIndiceMVP, &listaIndiceWinner, &totalRegistros);
=======
void lerCaracteres(char str[],int n);
void cadastrar(IPRIMARY **primaryList, IWINNER **winnerList, IMVP **mvpList);

int main(void){

	unsigned int opcMenu, opcSubMenu;
	IPRIMARY *primary = NULL;
	IWINNER *winner = NULL;
	IMVP *mvp = NULL;
    scanf("%u",&opcMenu);
    while(opcMenu > 0 && opcMenu < 8){
        printf("Valor Menu [%u] \n", opcMenu);
        switch(opcMenu){
            case 1:     
                //cadastrar;
                cadastrar(&primary, &winner, &mvp);
>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428
                break;
            case 2:
                //alterar; 
    
                break;
            case 3:
                //remover;     
                break;
            case 4:     
                //buscas;
                printf("Submenu\n");
<<<<<<< HEAD
                scanf("%d",&opcSubMenu);
                printf("Valor SubMenu [%d] \n", opcSubMenu);

                switch(opcSubMenu){

                    case 1:  
                        //buscaPorCodigo
                        getchar();
                        scanf("%[^\n]",strBuscaCodigo); 
                        getchar(); 
                        puts(strBuscaCodigo);
                        resultadoBuscaCodigo = buscarCodigoIndicePrimario(listaIndicePrimario, totalRegistros, strBuscaCodigo);
                        
                        if(resultadoBuscaCodigo == -1){
                            printf("Registro não encontrado!\n");
                        }else{
                            imprimirBuscaCodigo(resultadoBuscaCodigo, strBuscaCodigo);
                        }

=======
                scanf("%u",&opcSubMenu);
                printf("Valor SubMenu [%u] \n", opcSubMenu);

                switch(opcSubMenu){


                    case 1:  
                        //buscaPorCodigo   
>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428
                        break;
                    case 2:  
                        //buscaPorNomeEquipeVencedora   
                        break;
                    case 3:  
                        //buscaPorMVP   
                        break;
                    default: printf("Entrada invalida\n");
                }
                
                break;
            case 5:     
                //listagem;
                printf("Submenu\n");
<<<<<<< HEAD
                scanf("%d",&opcSubMenu);
                printf("Valor SubMenu [%d] \n", opcSubMenu);

                switch(opcSubMenu){
                    printf("Valor SubMenu [%d] \n", opcSubMenu);
                    case 1:  
                        //listagem por Codigo
                        listarPorCodigo(&listaIndicePrimario, &totalRegistros);
                        break;
                    case 2:  
                        //listagem por Winners
                        listarPorWinner(&listaIndiceWinner, &totalRegistros);
                        break;
                    case 3:  
                        //listagem por MVP's 
                        listarPorMVP(&listaIndiceMVP, &totalRegistros);  
                        break;
                    default: 
                        printf("Entrada invalida\n");
                        break;
=======
                scanf("%u",&opcSubMenu);
                printf("Valor SubMenu [%u] \n", opcSubMenu);

                switch(opcSubMenu){
                    printf("Valor SubMenu [%u] \n", opcSubMenu);
                    case 1:  
                        //buscaPorCodigo   
                        break;
                    case 2:  
                        //buscaPorNomeEquipeVencedora   
                        break;
                    case 3:  
                        //buscaPorMVP   
                        break;
                    default: printf("Entrada invalida\n");
>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428
                }


                break;
            case 6:     
                //liberar;
                break;
<<<<<<< HEAD
            case 7:
                //free(listaIndicePrimario);
                //free(listaIndiceMVP);
                //free(listaIndiceWinner);
                exit(0);
                break;
            default:    
                printf("Entrada invalida\n");
                break;
        }

    }while(opcMenu > 0 && opcMenu < 7);
=======
            case 7:     
				return 0;
                break;
            default:    
                printf("Entrada invalida\n");
        }

        scanf("%u",&opcMenu);
    }
>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428






	
	return 0;
}

<<<<<<< HEAD
int buscarCodigoIndicePrimario(IPRIMARY *listaIndicePrimario, int totalRegistros, char *codigo){
    int i=0;

    for( ; i < totalRegistros; i++)
        if( strcmp( (listaIndicePrimario + i)->codigo,  codigo) == 0)
            return (listaIndicePrimario + i)->rrn;
    
    return -1;
}

void cadastrarRegistro(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, IWINNER **listaIndiceWinner, int *totalRegistros){
	int bytes=0, i=0, contaLinha=0, existeChavePrimaria=0;
    FILE *matchesFile, *primaryFile, *winnerFile, *mvpFile;
    MATCHE novaPartida;
    
    matchesFile = fopen(DADOS_FILE, "a+");
    
    getchar();
	scanf("%[^\n]",novaPartida.equipeAzul); 
    getchar(); 
	//puts(novaPartida.equipeAzul);
    
    scanf("%[^\n]",novaPartida.equipeVermelha); 
    getchar();
	//puts(novaPartida.equipeVermelha);

    scanf("%[^\n]",novaPartida.data); 
    getchar();
    //puts(novaPartida.data);
	
    scanf("%[^\n]",novaPartida.duracao); 
    getchar();
    //puts(novaPartida.duracao);
	
    scanf("%[^\n]",novaPartida.equipeVencedora); 
    getchar();
    //puts(novaPartida.equipeVencedora);
	
    scanf("%[^\n]",novaPartida.placarAzul); 
    getchar();
    //puts(novaPartida.placarAzul);
	
    scanf("%[^\n]",novaPartida.placarVermelha); 
    getchar();
    //puts(novaPartida.placarVermelha);
	
    scanf("%[^\n]",novaPartida.apelidoMVP); 
    getchar();
    //puts(novaPartida.apelidoMVP);
=======
void cadastrar(IPRIMARY **primaryList, IWINNER **winnerList, IMVP **mvpList){
	int bytes=0, i = 0,totalRegistros = 0;
    FILE *matchesFile, *primaryFile;
    MATCHE novaPartida;
    matchesFile = fopen(DADOS_FILE, "a");

    if(matchesFile == NULL) perror("Erro ao abrir o arquivo \n");
    else printf("Arquivo aberto para leitura \n");

	scanf("\n%[^\n]s",novaPartida.equipeAzul);
	scanf("\n%[^\n]s",novaPartida.equipeVermelha);	
	scanf("\n%[^\n]s",novaPartida.data);
	scanf("\n%[^\n]s",novaPartida.duracao);
	scanf("\n%[^\n]s",novaPartida.equipeVencedora);
	scanf("\n%[^\n]s",novaPartida.placarAzul);
	scanf("\n%[^\n]s",novaPartida.placarVermelha);	
	scanf("\n%[^\n]s",novaPartida.apelidoMVP);

>>>>>>> bbf94349f6b4722910c083cd8d269ac2a8c9c428

    novaPartida.codigo[0] = novaPartida.equipeAzul[0];
    novaPartida.codigo[1] = novaPartida.equipeVermelha[0];
    novaPartida.codigo[2] = novaPartida.apelidoMVP[0];
    novaPartida.codigo[3] = novaPartida.apelidoMVP[1];
    novaPartida.codigo[4] = novaPartida.data[0];
    novaPartida.codigo[5] = novaPartida.data[1];
    novaPartida.codigo[6] = novaPartida.data[3];
    novaPartida.codigo[7] = novaPartida.data[4];
    novaPartida.codigo[8] = '\0';
<<<<<<< HEAD

    //puts(novaPartida.codigo);


    if(*totalRegistros != 0)
        existeChavePrimaria = buscarCodigoIndicePrimario(*listaIndicePrimario, *totalRegistros, novaPartida.codigo);
    else
        existeChavePrimaria = -1;

    printf("Valor de existeChavePrimaria[%d]\n", existeChavePrimaria);

    if( existeChavePrimaria == -1 ){

        //Aloca espaço para o novo registro na lista de índices primários.
        *listaIndicePrimario = (IPRIMARY*) realloc(*listaIndicePrimario, sizeof(IPRIMARY) * (*totalRegistros + 1));
        //Aloca espaço para o novo registro na lista de títulos
        *listaIndiceMVP = (IMVP*) realloc(*listaIndiceMVP, sizeof(IMVP) * (*totalRegistros + 1) );
        //Aloca espaço para o novo registro na lista de títulos
        *listaIndiceWinner = (IWINNER*) realloc(*listaIndiceWinner, sizeof(IWINNER) * (*totalRegistros + 1) );
        
        //Insere o novo registro na lista de índices primários.
        strcpy( (*listaIndicePrimario + *totalRegistros)->codigo, novaPartida.codigo);
        (*listaIndicePrimario + *totalRegistros)->rrn = ++(*totalRegistros);
        
        //Insere o novo registro na lista de títulos.
        strcpy((*listaIndiceMVP + (*totalRegistros - 1))->iMVP, novaPartida.apelidoMVP);
        strcpy((*listaIndiceMVP + (*totalRegistros - 1))->codigo, novaPartida.codigo);
        
        //Insere o novo registro na lista de títulos.
        strcpy((*listaIndiceWinner + (*totalRegistros - 1))->iEquipeVencedora, novaPartida.equipeVencedora);
        strcpy((*listaIndiceWinner + (*totalRegistros - 1))->codigo, novaPartida.codigo);

        
        primaryFile = fopen(PRIMARY_FILE, "a");
        if (primaryFile != NULL){
            fprintf(primaryFile,"%s%c%d%c%c", novaPartida.codigo, '@', *totalRegistros, '@', '\n');
            fclose(primaryFile);
        }

        winnerFile = fopen(WINNER_FILE, "a");
        if (winnerFile != NULL){
            fprintf(winnerFile,"%s%c%s%c%c", novaPartida.equipeVencedora, '@', novaPartida.codigo, '@', '\n');
            fclose(winnerFile);
        }

        mvpFile = fopen(MVP_FILE,"a");
        if (mvpFile != NULL){
            fprintf(mvpFile,"%s%c%s%c%c", novaPartida.apelidoMVP, '@',novaPartida.codigo, '@', '\n');
            fclose(mvpFile);
        }

        
        if(matchesFile != NULL){
            bytes = fprintf(matchesFile,"%s@%s@%s@%s@%s@%s@%s@%s@%s@",
                                                            novaPartida.codigo,
                                                            novaPartida.equipeAzul,
                                                            novaPartida.equipeVermelha,
                                                            novaPartida.data,
                                                            novaPartida.duracao,
                                                            novaPartida.equipeVencedora,
                                                            novaPartida.placarAzul,
                                                            novaPartida.placarVermelha,
                                                            novaPartida.apelidoMVP);
        
            for(i = 0; i < MAX_REGISTRO - bytes; i++)
                fprintf(matchesFile, "#");

            fclose(matchesFile);
        }
	}

}


void carregarIndicePrimario(IPRIMARY **listaIndicePrimario, int *totalRegistros){
    FILE *iprimaryFile;
    char auxStr[MAX_INDICE], *token;
    int i=0;
   
    iprimaryFile = fopen(PRIMARY_FILE, "r");

    if(*totalRegistros > 0){
        if(iprimaryFile){
            
            *listaIndicePrimario = (IPRIMARY *) malloc( sizeof(IPRIMARY) * *totalRegistros);

            while( i < *totalRegistros ){
                fgets(auxStr, MAX_INDICE, iprimaryFile);
                if ( (strcmp(auxStr,"\n") != 0) ){
                    token = strtok(auxStr, "@");  
                    strcpy( (*listaIndicePrimario + i)->codigo, token);
                    token = strtok(NULL, "@");
                    (*listaIndicePrimario + i)->rrn = atoi(token);
                    i++;
                }
            }
            fclose(iprimaryFile);
        }
    }
}


void carregarIndiceMVP(IMVP **listaIndiceMVP, int *totalRegistros){
    FILE *iMVPFile;
    char auxStr[MAX_INDICE], *token;
    int i=0;

    iMVPFile = fopen(MVP_FILE, "r");

    if(*totalRegistros > 0){
        if(iMVPFile){
            *listaIndiceMVP = (IMVP *) malloc( sizeof(IMVP) * *totalRegistros );//Aloca o espaço para os dados do arquivo de índice.
            while( i < *totalRegistros ){
                fgets(auxStr, MAX_INDICE, iMVPFile);
                if ( (strcmp(auxStr,"\n") != 0) ){
                    token = strtok(auxStr, "@");  
                    strcpy( (*listaIndiceMVP + i)->iMVP, token);
                    token = strtok(NULL, "@");
                    strcpy( (*listaIndiceMVP + i)->codigo, token );
                    i++;
                }
            }
            fclose(iMVPFile);
        }
    }
 
}

void carregarIndiceWinner(IWINNER **listaIndiceWinner, int *totalRegistros){
    FILE *winnerFile;
    char auxStr[MAX_INDICE], *token;
    int i=0;

    winnerFile = fopen(WINNER_FILE, "r");

    if(*totalRegistros > 0){
        if(winnerFile){
            
            *listaIndiceWinner = (IWINNER *) malloc( sizeof(IWINNER) * *totalRegistros );//Aloca o espaço para os dados do arquivo de índice.

            while( i < *totalRegistros ){
                fgets(auxStr, MAX_INDICE, winnerFile);
                if ( (strcmp(auxStr,"\n") != 0) ){
                    token = strtok(auxStr, "@");  
                    strcpy( (*listaIndiceWinner + i)->iEquipeVencedora, token);
                    token = strtok(NULL, "@");
                    strcpy( (*listaIndiceWinner + i)->codigo, token );
                    i++;
                }
            }
            fclose(winnerFile);
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------
int compararIndicePrimario(const void *str1, const void *str2){
    return strcmp( ((IPRIMARY*)str1)->codigo, ((IPRIMARY*)str2)->codigo);
}

//------------------------------------------------------------------------------------------------------------------------
int compararIndiceMVP(const void *str1, const void *str2){
    return strcmp(((IMVP*)str1)->iMVP, ((IMVP*)str2)->iMVP);
}

//------------------------------------------------------------------------------------------------------------------------
int compararIndiceWinner(const void *str1, const void *str2){
    return strcmp(((IWINNER*)str1)->iEquipeVencedora, ((IWINNER*)str2)->iEquipeVencedora);
}

void imprimirBuscaCodigo(int rrnCodigo, char *codigo){
    FILE *dataFile;
    char auxStr[MAX_REGISTRO], *tokenAux;

    dataFile = fopen(DADOS_FILE,"r");

    fseek(dataFile, rrnCodigo*MAX_REGISTRO, SEEK_SET);

    fgets(auxStr,MAX_REGISTRO,dataFile);

    tokenAux = strtok(auxStr,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);
    tokenAux = strtok(NULL,"@");
    printf("%s\n", tokenAux);


}


void listarPorCodigo(IPRIMARY **listaIndicePrimario, int *totalRegistros){
    int i=0;
    ordenarIndicePrimario(listaIndicePrimario, *totalRegistros);
    printf("IMPRESSAO DAS LISTAS de chave PRIMARIA\n");
    for ( ; i < *totalRegistros; i++)
        printf("Chave Primaria[%d] --- Codigo[%s] com RRN[%d] \n", i+1, (*listaIndicePrimario + i)->codigo, (*listaIndicePrimario + i)->rrn);
}

void listarPorMVP(IMVP **listaIndiceMVP, int *totalRegistros){
    int i=0;
    ordenarIndiceMVP(listaIndiceMVP, *totalRegistros);
    printf("IMPRESSAO DAS LISTAS de MVP \n");
    for ( ; i < *totalRegistros; i++)
        printf("Chave MVP[%d] --- MVP[%s] com Codigo[%s] \n", i+1, (*listaIndiceMVP + i)->iMVP, (*listaIndiceMVP + i)->codigo);
}

void listarPorWinner(IWINNER **listaIndiceWinner, int *totalRegistros){
    int i = 0;
    ordenarIndiceWinner(listaIndiceWinner, *totalRegistros);
    printf("IMPRESSAO DAS LISTAS de Winner \n");
    for ( ; i < *totalRegistros; i++)
        printf("Chave Winner[%d] --- Winner[%s] com Codigo[%s] \n", i+1, (*listaIndiceWinner + i)->iEquipeVencedora, (*listaIndiceWinner + i)->codigo);
}

//------------------------------------------------------------------------------------------------------------------------
void ordenarIndicePrimario(IPRIMARY **listaIndicePrimario, int totalRegistros){
    qsort(*listaIndicePrimario, totalRegistros, sizeof(IPRIMARY), compararIndicePrimario);
}

void ordenarIndiceMVP(IMVP **listaIndiceMVP, int totalRegistros){
    qsort(*listaIndiceMVP, totalRegistros, sizeof(IMVP), compararIndiceMVP);
}
void ordenarIndiceWinner(IWINNER **listaIndiceWinner, int totalRegistros){
    qsort(*listaIndiceWinner, totalRegistros, sizeof(IWINNER), compararIndiceWinner);
}
