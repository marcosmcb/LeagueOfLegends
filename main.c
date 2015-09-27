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


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DADOS_FILE "teste.dat"
#define PRIMARY_FILE "iprimary.idx"
#define WINNER_FILE "iwinner.idx"
#define MVP_FILE "imvp.idx"
#define MAX_REGISTRO 192

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

int buscarCodigo(IPRIMARY *lista, int totalRegistros, char *codigo);
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
                scanf("%u",&opcSubMenu);
                printf("Valor SubMenu [%u] \n", opcSubMenu);

                switch(opcSubMenu){


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
                }
                
                break;
            case 5:     
                //listagem;
                printf("Submenu\n");
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
                }


                break;
            case 6:     
                //liberar;
                break;
            case 7:     
                return 0;
                break;
            default:    
                printf("Entrada invalida\n");
                exit(0);
                break;
        }

        scanf("%u",&opcMenu);
    }

    return 0;
}

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


    novaPartida.codigo[0] = novaPartida.equipeAzul[0];
    novaPartida.codigo[1] = novaPartida.equipeVermelha[0];
    novaPartida.codigo[2] = novaPartida.apelidoMVP[0];
    novaPartida.codigo[3] = novaPartida.apelidoMVP[1];
    novaPartida.codigo[4] = novaPartida.data[0];
    novaPartida.codigo[5] = novaPartida.data[1];
    novaPartida.codigo[6] = novaPartida.data[3];
    novaPartida.codigo[7] = novaPartida.data[4];
    novaPartida.codigo[8] = '\0';
    
    totalRegistros = ftell(matchesFile) / MAX_REGISTRO;
    
    /* Aloca espaço para a lista dos indices primários */
    *primaryList = (IPRIMARY*) realloc(*primaryList, sizeof(IPRIMARY) * totalRegistros);
    /* Aloca espaço para a lista dos times vencedores */
    *winnerList = (IWINNER*) realloc(*winnerList, sizeof(IWINNER) * totalRegistros);
    /* Aloca espaço para a lista dos MVPs */
    *mvpList = (IMVP*) realloc(*mvpList, sizeof(IMVP) * totalRegistros);

    //Percorre a lista de índices procurando pela chave *codigo;
    if( buscarCodigo(*primaryList, totalRegistros, novaPartida.codigo) != -1){       

        //Insere o novo registro na lista de índices primários.
        strcpy( *(IPRIMARY)[totalRegistros].codigo, novaPartida.codigo);
        *(IPRIMARY)[totalRegistros].rrn = ++totalRegistros;
        
        //Insere o novo registro na lista de títulos.
        strcpy( *(IWINNER)[totalRegistros - 1].iEquipeVencedora, novaPartida.equipeVencedora);
        strcpy( *(IWINNER)[totalRegistros - 1].codigo, novaPartida.codigo);
        
        //Insere o novo registro na lista de títulos.
        strcpy( *(IMVP)[totalRegistros - 1].iMVP, novaPartida.apelidoMVP);
        strcpy( *(IMVP)[totalRegistros - 1].codigo, novaPartida.codigo);


        primaryFile = fopen(WINNER_FILE,"a+");

        if(primaryFile != NULL) {

            bytes = fprintf(matchesFile,"%s@%s@%s@%s@%s@%s@%s@%s@%s@",
                                novaPartida.codigo,novaPartida.equipeAzul, 
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
        
        ordenarIndices(primario, titulo, autores, *total);
    }
    
}




int buscarPorCodigo(iprimary *lista, int totalRegistros, char *codigo){
    int i;
    
    //Percorre a lista de índices procurando pela chave *codigo;
    for(i = 0; i < totalRegistros; i++){
        if(!strcmp(lista[i].chave, codigo))
            return lista[i].pos;//Retorna RRN (que pode ser -1, indicando que o resgistro foi apagado).
    }
    
    //Valor não encontrado.
    return -1;
}






