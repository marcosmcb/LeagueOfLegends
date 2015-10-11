/*******************************************
Trabalho 1 - Estrutura de Dados 2
            INDEXAÇÃO
Prof. Tiago A. Almeida
Autores:
        Marcos Cavalvante     408336
        Yanick Oliveira Rossi 408646
        
        ARQUIVO .H COM A DEFINICAO DAS FUNÇOES

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
#ifndef LISTAD_H
#define LISTAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


#define DADOS_FILE "matches.dat"
#define PRIMARY_FILE "iprimary.idx"
#define WINNER_FILE "iwinner.idx"
#define MVP_FILE "imvp.idx"
#define MAX_REGISTRO 192
#define MAX_INDICE 50

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

void alterarRegistro(int rrnRegistroAlterar);
void atualizarIndicesDisco(IPRIMARY **listaIndicePrimario, IWINNER **listaIndiceWinner, IMVP **listaIndiceMVP, int *totalRegistros);

int buscarCodigoIndicePrimario(IPRIMARY *listaIndicePrimario, int totalRegistros, char *codigo);
int buscarEquipeResultado(IPRIMARY *listaIndicePrimario, IWINNER *listaIndiceWinner, int totalRegistros, char *strBuscaEquipe, int **vetorRrnEquipes);
int buscarMvpResultado(IPRIMARY *listaIndicePrimario, IMVP *listaIndiceMVP, int totalRegistros, char *strBuscaMVP, int **vetorRrnMvps);

void cadastrarRegistro(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, IWINNER **listaIndiceWinner, int *totalRegistros);

int carregarIndicePrimario(IPRIMARY **listaIndicePrimario, int *totalRegistros);
int carregarIndiceMVP(IMVP **listaIndiceMVP, int *totalRegistros);
int carregarIndiceWinner(IWINNER **listaIndiceWinner, int *totalRegistros);

int checkarNomeEquipeMVP(char *nome);
int checkarData(char *data);
int checkarDuracao(char *duracao);
int checkarDuracao1(char *duracao);
int checkarPlacar(char *placar);
int checkarVencedor(char *equipeVencedora, char *equipeAzul, char *equipeVermelha);

int compararIndicePrimario(const void *str1, const void *str2);
int compararIndiceMVP(const void *str1, const void *str2);
int compararIndiceWinner(const void *str1, const void *str2);

void imprimirBuscaCodigo(int rrnCodigo);
void imprimirBuscaEquipeMVP(int resultadoBuscaEquipe, int **vetorRrnEquipes);

void liberarArquivoDadosIndice(IPRIMARY **listaIndicePrimario, IWINNER **listaIndiceWinner, IMVP **listaIndiceMVP, int *totalRegistros);

void listarPorCodigo(IPRIMARY **listaIndicePrimario, int *totalRegistros);
void listarPorMVP(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, int *totalRegistros);
void listarPorWinner(IPRIMARY **listaIndicePrimario, IWINNER **listaIndiceWinner, int *totalRegistros);
void listarBuscaEquipeMVP(MATCHE **resultadoBuscaEquipeMVP, int resultadoBuscaEquipe);


void ordenarIndicePrimario(IPRIMARY **listaIndicePrimario, int totalRegistros);
void ordenarIndiceMVP(IMVP **listaIndiceMVP, int totalRegistros);
void ordenarIndiceWinner(IWINNER **listaIndiceWinner, int totalRegistros);
void ordenarBuscaEquipeMVP(MATCHE **equipesBuscadas, int totalRegistros);
void ordenarIndices(IPRIMARY **listaIndicePrimario,  IWINNER **listaIndiceWinner, IMVP **listaIndiceMVP, int totalRegistros);

void refazerIndices(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, IWINNER **listaIndiceWinner, int totalRegistros);
void removerRegistro(int rrnRegistroRemover, char *valorChavePK, IPRIMARY **listaIndicePrimario, int *totalRegistros);

#endif
