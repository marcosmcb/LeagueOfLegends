/*******************************************
Trabalho 1 - Estrutura de Dados 2
            INDEXAÇÃO
Prof. Tiago A. Almeida
Autores:
        Marcos Cavalvante     408336
        Yanick Oliveira Rossi 408646
        
        ARQUIVO MAIN

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

    COMO RODAR O PROGRAMA:  make clean && make && ./main

    Se você preferir não usar o MAKE, use: gcc -o main main.c

    Alternativamente, use nosso Shell script:

    chmod +x testes.sh && ./testes.sh

********************************************/

#include "408336_408646_ED2_T01.h"

int main(void){
	
    int opcMenu, opcSubMenu, totalRegistros, flags=0;;
    int resultadoBuscaCodigo, resultadoBuscaEquipe, resultadoBuscaMVP, resultadoAlterarDuracao, resultadoRemove; 
    int *vetorRrnEquipes = NULL, *vetorRrnMvps = NULL;
    char strBuscaCodigo[9], strBuscaEquipe[39], strBuscaMVP[39], strAlteraDuracao[9], strRemoveRegistro[9];
	
    FILE *dataFile;
    IPRIMARY *listaIndicePrimario = NULL;
    IWINNER *listaIndiceWinner = NULL;
    IMVP *listaIndiceMVP = NULL;

    dataFile = fopen(DADOS_FILE,"a");
    /*Contamos o total de registros dentro do arquivo de dados pelo calculo do ftell(quantidade de bytes) dividido pela quantidade bytes de cada registro*/
    totalRegistros = (int) ( ftell(dataFile) / MAX_REGISTRO );
    /*DEBUG*/
    //printf("Valor de FTELL [%d]\n", ftell(dataFile) );

    fclose(dataFile);

    /*
        CARREGAMOS OS INDICES NA MEMORIA, PASSANDO COMO PARAMETRO UM PONTEIRO PARA CADA RESPECTIVA STRUCT 
        E O TOTAL DE REGISTROS DO ARQUIVO DE DADOS, AMBOS DEVEM TER A MESMA QUANTIDADE DE REGISTROS
    */

    flags += carregarIndicePrimario(&listaIndicePrimario, &totalRegistros);
    flags += carregarIndiceMVP(&listaIndiceMVP, &totalRegistros);
    flags += carregarIndiceWinner(&listaIndiceWinner, &totalRegistros);
    //printf("Valor de flags[%d]\n", flags);
    if(flags == -3){
        refazerIndices(&listaIndicePrimario, &listaIndiceMVP, &listaIndiceWinner, totalRegistros);
        atualizarIndicesDisco(&listaIndicePrimario, &listaIndiceWinner, &listaIndiceMVP, &totalRegistros); 
    }

    do{ 
        scanf("%d", &opcMenu);
        //printf("Valor Menu [%d] \n", opcMenu);
        
        switch(opcMenu){
            case 1:     
                //cadastrar;
                cadastrarRegistro(&listaIndicePrimario, &listaIndiceMVP, &listaIndiceWinner, &totalRegistros);
                break;

            /* 
            FAZ A BUSCA NO ARQUIVO DE INDICE PELA CHAVE PRIMARIA, E TEM COMO RETORNO DA BUSCA O RRN 
            SE A BUSCA RETORNAR -1, REGISTRO NAO ENCONTRADO; CASO CONTRARIO, NOS CHAMAMOS A FUNCAO DE ALTERAR
            RRN(resultadoAlterarDuracao) EH PASSADO COMO PARAMETRO PRA FUNCAO
            */
            case 2:
                //alterar;
                getchar();
                scanf("%[^\n]",strAlteraDuracao); //PASSA A CHAVE PRIMARIA
                getchar();
                resultadoAlterarDuracao = buscarCodigoIndicePrimario(listaIndicePrimario, totalRegistros, strAlteraDuracao);

                if( resultadoAlterarDuracao == -1 )
                    printf("Registro Não encontrado!\n");
                else
                    alterarRegistro(resultadoAlterarDuracao);

                break;

            /* 
            FAZ A BUSCA NO ARQUIVO DE INDICE PELA CHAVE PRIMARIA, E TEM COMO RETORNO DA BUSCA O RRN 
            SE A BUSCA RETORNAR -1, REGISTRO NAO ENCONTRADO; CASO CONTRARIO, NOS CHAMAMOS A FUNCAO DE ALTERAR 
            RRN(resultadoRemove) EH PASSADO COMO PARAMETRO PRA FUNCAO, ASSIM COMO A CHAVE QUE VAI SER REMOVIDA
            */
            case 3:
                //remover; 
                getchar();
                scanf("%[^\n]",strRemoveRegistro); //PASSA A CHAVE PRIMARIA
                getchar();
                
                resultadoRemove = buscarCodigoIndicePrimario(listaIndicePrimario, totalRegistros, strRemoveRegistro);
                
                if( resultadoRemove == -1 )
                    printf("Registro Não encontrado!\n");
                else{
                    removerRegistro(resultadoRemove, strRemoveRegistro, &listaIndicePrimario, &totalRegistros);
                }

                break;
            case 4:     
                //buscas;
                
                scanf("%d",&opcSubMenu);

                switch(opcSubMenu){
                    /*
                    FAZEMOS A BUSCA PASSANDO A CHAVE PRIMARIA (CODIGO) E TEMOS COMO RETORNO O RRN, QUE USAMOS PRA IMPRIMIR O REGISTRO DEPOIS
                    SE FOR -1, REGISTRO NAO ENCONTRADO, CASO CONTRARIO, IMPRIMOS O REGISTRO COM RRN (resultadoBuscaCodigo) ACHADO
                    */
                    case 1:  
                        //buscaPorCodigo
                        getchar();
                        scanf("%[^\n]",strBuscaCodigo); 
                        getchar(); 

                        resultadoBuscaCodigo = buscarCodigoIndicePrimario(listaIndicePrimario, totalRegistros, strBuscaCodigo);
                        
                        if(resultadoBuscaCodigo == -1)
                            printf("Registro não encontrado!\n");
                        else
                            imprimirBuscaCodigo(resultadoBuscaCodigo);

                        break;
                     /*
                        REALIZAMOS A BUSCA ATRAVES DO NOME DA EQUIPE, E COM ISSO, TEMOS COMO RETORNO DA FUNCAO buscarEquipeResultado,
                        A QUANTIDADE DE REGISTROS ENCONTRADOS, E OS RRNS DESSES REGISTROS ESTAO ARMAZENADOS NO VETOR(vetorRrnEquipe) QUE FOI
                        PASSADO POR REFERENCIA NA FUNCAO 
                    */
                    case 2:  
                        //buscaPorNomeEquipeVencedora
                        getchar();
                        do{
                            scanf("%[^\n]",strBuscaEquipe); 
                            getchar();
                        }while( checkarNomeEquipeMVP(strBuscaEquipe) );
                        
                        resultadoBuscaEquipe = buscarEquipeResultado(listaIndicePrimario, listaIndiceWinner, totalRegistros, strBuscaEquipe, &vetorRrnEquipes);

                        if(resultadoBuscaEquipe == 0){
                            printf("Registro não encontrado!\n");
                        }
                        else{
                            imprimirBuscaEquipeMVP(resultadoBuscaEquipe, &vetorRrnEquipes);
                            free(vetorRrnEquipes);
                        }

                        
                    
                        break;
                    /*
                        REALIZAMOS A BUSCA ATRAVES DO NOME DO MVP, E COM ISSO, TEMOS COMO RETORNO DA FUNCAO buscarMvpResultado,
                        A QUANTIDADE DE REGISTROS ENCONTRADOS, E OS RRNS DESSES REGISTROS ESTAO ARMAZENADOS NO VETOR(vetorRrnMvps) QUE FOI
                        PASSADO POR REFERENCIA NA FUNCAO 
                    */
                    case 3:  
                        //buscaPorMVP   
                        getchar();
                        
                        do{
                            scanf("%[^\n]",strBuscaMVP); 
                            getchar();
                        }while( checkarNomeEquipeMVP(strBuscaMVP) );

                        resultadoBuscaMVP = buscarMvpResultado(listaIndicePrimario, listaIndiceMVP, totalRegistros, strBuscaMVP, &vetorRrnMvps);
                        
                        if(resultadoBuscaMVP == 0)
                            printf("Registro não encontrado!\n");
                        else
                            imprimirBuscaEquipeMVP(resultadoBuscaMVP, &vetorRrnMvps);

                        free(vetorRrnMvps);

                        break;
                    default: printf("Entrada invalida\n");
                }
                
                break;
            case 5:     
                //listagem;
                scanf("%d",&opcSubMenu);

                switch(opcSubMenu){
                    /* 
                    NOS BASICAMENTE LISTAMOS TODOS OS REGISTROS EM NOSSO ARQUIVO DE DADOS, APENAS COM
                    EXCECAO OS REGISTROS MARCADOS COMO EXCLUIDOS
                    */
                    case 1:  
                        //listagem por Codigo
                        if(totalRegistros==0){
                            printf("Arquivo vazio!\n");
                        }
                        else{
                            listarPorCodigo(&listaIndicePrimario, &totalRegistros);
                        }

                        break;
                    
                    case 2:  
                        //listagem por Winners
                        /*LISTAGEM BASICA DE TODOS OS REGISTROS QUE ESTAO NAS LISTAS EM QUE O RRN EH DIFERENTE DE -1*/
                        if(totalRegistros==0){
                            printf("Arquivo vazio!\n");
                        }
                        else{
                            listarPorWinner(&listaIndicePrimario, &listaIndiceWinner, &totalRegistros);
                        }

                        break;
                    
                    case 3:  
                        //listagem por MVP's
                        /*LISTAGEM BASICA DE TODOS OS REGISTROS QUE ESTAO NAS LISTAS EM QUE O RRN EH DIFERENTE DE -1*/
                        if(totalRegistros==0){
                            printf("Arquivo vazio!\n");
                        }
                        else{
                            listarPorMVP(&listaIndicePrimario, &listaIndiceMVP, &totalRegistros); 
                        }

                        break;

                    default: 
                        printf("Entrada invalida\n");
                        break;
                }


                break;
            case 6:     
                //liberar;
                if(totalRegistros > 0){
                    liberarArquivoDadosIndice(&listaIndicePrimario, &listaIndiceWinner, &listaIndiceMVP, &totalRegistros);
                }
                
                break;
            case 7:
                /*
                REALIZAMOS A ATUALIZACAO DOS ARQUIVOS DE INDICES, ESCREVENDO O CONTEUDO QUE TEM SIDO MANIPULADO EM MEMORIA 
                DENTRO DAS LISTAS DE INDICE PRIMARIO, WINNER E MVP

                FINALMENTE LIBERAMOS OS PONTEIROS QUE CARREGAM OS ARQUIVOS DE INDICES NA MEMORIA
                
                SAI DO PROGRAMA COM SUCESSO
                */

                if(totalRegistros > 0){
                    atualizarIndicesDisco(&listaIndicePrimario, &listaIndiceWinner, &listaIndiceMVP, &totalRegistros);
                }
                
                free(listaIndicePrimario);
                free(listaIndiceMVP);
                free(listaIndiceWinner);
                exit(0); 

                break;
            default:    
                printf("Entrada invalida\n");
                break;
        }

    }while(opcMenu > 0 && opcMenu < 7);
	
	return 0;
}

