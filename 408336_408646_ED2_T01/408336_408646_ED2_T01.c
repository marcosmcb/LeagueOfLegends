/*******************************************
Trabalho 1 - Estrutura de Dados 2
            INDEXAÇÃO
Prof. Tiago A. Almeida
Autores:
        Marcos Cavalvante     408336
        Yanick Oliveira Rossi 408646
        
        ARQUIVO .C COM A IMPLEMENTACAO DAS FUNCOES NO .H

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

//------------------------------------------------FUNCOES PARA ALTERAR REGISTROS ---------------------------------------------------

/*
    PARA ALTERAR UM REGISTRO, EH NECESSARIO QUE SEJA INFORMADO PRIMEIRAMENTE O CODIGO DE TAL REGISTRO (NO MAIN)
    E DEPOIS PROSSIGUIMOS COM A BUSCA, PEDIMOS O VALOR DA DURACAO, NO FORMATO CORRETO, E QUANDO O MESMO EH DIGITADO
    PROSSEGUIMOS COM A ALTERACAO, PROCURANDO NO ARQUIVO DE DADOS, E QUANDO O REGISTRO EH ENCONTRADO, PUXAMOS O REGISTRO
    INTEIRO DE 192 BYTES, ALTERAMOS O QUE NOS INTERESSA E REESCREVEMOS DE VOLTA.
*/

void alterarRegistro(int rrnRegistroAlterar){
    int i=0, contArrobas=0, j=0, flag=1;
    char alterarDuracao[6], carregarRegistro[MAX_REGISTRO];
    FILE *dataFile;

    do{

        scanf("%[^\n]",alterarDuracao); 
        getchar();  
    
    }while( checkarDuracao1(alterarDuracao) );

    if( (dataFile = fopen(DADOS_FILE, "r+" ) ) ){
        
        fseek( dataFile, (rrnRegistroAlterar - 1) * MAX_REGISTRO, SEEK_SET );
        fgets(carregarRegistro, MAX_REGISTRO, dataFile);
        

        for(i=0; carregarRegistro[i] != '\0'; i++){
            /*CONTA O NUMERO DE DELIMITADORES*/
            if(carregarRegistro[i] == '@')
                contArrobas++;
            /*SE FOR IGUAL A 4 EH PQ EU CHEGUEI NO CAMPO EM QUE EU DESEJO ALTERAR*/
            if(contArrobas == 4 && flag == 1){
                flag--;
                carregarRegistro[i] = carregarRegistro[i];
                i +=1;
                /*
                COMO O CAMPO TEM NO MAXIMO 5 BYTES, APENAS COPIO OS 5 PRIMEIROS BYTES 
                INFORMADOS PELO USUARIO, COM EXCECAO DO \0
                */
                for(j=0; j < 5; j++)
                    carregarRegistro[i++] = alterarDuracao[j];
                
            }else{
                carregarRegistro[i] = carregarRegistro[i];
            }
            
        }

        fseek( dataFile, (rrnRegistroAlterar - 1) * MAX_REGISTRO, SEEK_SET);
        fprintf( dataFile,"%s", carregarRegistro);
        
        fclose(dataFile);
    }
   
}

/*  
    FUNCAO PARA ATUALIZAR OS INDICES NO DISCO.
    CHAMO A FUNCAO DE ORDENACAO DE INDICES NOVAMENTE, APENAS PRA GARANTIR A ORDENACAO DOS INDICES ANTES DE ESCREVE-LOS, 

    ACHO QUE ESSA CHAMADA EH REDUNDANTE NO ENTANTO

    FINALMENTE, PROSSIGO ABRINDO CADA ARQUIVO DE INDICE E ESCREVENDO O CONTEUDO DAS LISTAS

*/
    
void atualizarIndicesDisco(IPRIMARY **listaIndicePrimario, IWINNER **listaIndiceWinner, IMVP **listaIndiceMVP, int *totalRegistros){
    int i=0;
    FILE *primaryFile, *winnerFile, *mvpFile;
    
    ordenarIndices( listaIndicePrimario, listaIndiceWinner, listaIndiceMVP, *totalRegistros);

   
    if( ( primaryFile = fopen( PRIMARY_FILE, "w" ) ) ){
        fputc('1', primaryFile);
        fputc('\n', primaryFile);
        for(i=0 ; i < *totalRegistros; i++){
            fprintf(primaryFile,"%s%c%d%c%c", (*listaIndicePrimario + i)->codigo , '@', (*listaIndicePrimario + i)->rrn, '@', '\n');
        }

        fclose(primaryFile);
    }

    
    if ( ( winnerFile = fopen(WINNER_FILE, "w" ) ) ){
        
        fputc('1', winnerFile);
        fputc('\n', winnerFile);

        for(i=0 ; i < *totalRegistros; i++){
            fprintf(winnerFile,"%s%c%s%c%c", (*listaIndiceWinner + i)->iEquipeVencedora , '@', (*listaIndiceWinner + i)->codigo, '@', '\n');
        }
        
        fclose(winnerFile);
    }

    
    if ( ( mvpFile = fopen( MVP_FILE,"w" ) ) ){
        
        fputc('1', mvpFile);
        fputc('\n', mvpFile);

        for(i=0 ; i < *totalRegistros; i++){
            fprintf(mvpFile,"%s%c%s%c%c", (*listaIndiceMVP + i)->iMVP, '@', (*listaIndiceMVP + i)->codigo , '@', '\n');
        }
        
        fclose(mvpFile);
    }

}


//------------------------------------------------FUNCOES PARA BUSCAR REGISTROS ---------------------------------------------------


/*  
    FUNCAO PARA BUSCA PELA CHAVE PRIMARIA, RECEBE A LISTA DE CHAVE PRIMARIAS E O TOTAL DE REGISTROS(totalRegistros), 
    ASSIM COMO A CHAVE A SER BUSCADA(CODIGO)

    UMA BUSCA BINARIA PODERIA TER SIDO FEITA, MAS NUM PRIMEIRO MOMENTO, FOCAMOS APENAS NA FUNCIONALIDADE BASICA DA APLICACAO,
    SERIA UMA ALTERNATIVA INTERESSANTE USAR A FUNCAO BSEARCH DO C.
    
    SENAO, RETORNA -1, REPARE QUE ISSO FUNCIONA MESMO QUE PARA REGISTROS QUE TENHAM SIDO MARCADOS COMO EXCLUIDOS
*/
int buscarCodigoIndicePrimario(IPRIMARY *listaIndicePrimario, int totalRegistros, char *codigo){
    int i=0;

    for( ; i < totalRegistros; i++){
        if( strcmp( (listaIndicePrimario + i)->codigo,  codigo) == 0 ){
            return (listaIndicePrimario + i)->rrn; /*RETORNA O RRN CASO ENCONTRADO*/
        }
    }
    
    return -1; 
}


/*
    BUSCA PELA EQUIPE INFORMADA, COMPARADO-SE O NOME DA EQUIPE COM AQUELES QUE ESTAO NA LISTA EM MEMORIA PRINCIPAL, 
    E TODA VEZ QUE UMA EQUIPE EH ENCONTRADA, SEU RRN EH ARMAZENADO NO VETOR DE RRNS; POR FIM, RETORNAMOS A QUANTIDADE DE REGISTROS ENCONTRADOS,
    ATRAVES DA VARIAVEL ACHOU
*/
int buscarEquipeResultado(IPRIMARY *listaIndicePrimario, IWINNER *listaIndiceWinner, int totalRegistros, char *strBuscaEquipe, int **vetorRrnEquipes){
    int i=0, achouEquipe = 0;
    
    *vetorRrnEquipes = (int*) malloc(sizeof(int) * (achouEquipe+1) );

    for ( ; i < totalRegistros; i++){
        if ( strcmp( (listaIndiceWinner + i)->iEquipeVencedora, strBuscaEquipe ) == 0 ){
            *vetorRrnEquipes = (int*) realloc(*vetorRrnEquipes, sizeof(int) * (achouEquipe+1) );
            (*vetorRrnEquipes)[achouEquipe] = buscarCodigoIndicePrimario( listaIndicePrimario, totalRegistros, (listaIndiceWinner + i)->codigo )    ;
            achouEquipe += ( (*vetorRrnEquipes)[achouEquipe] == -1) ? 0 : 1;
        }
    }

    return achouEquipe;
}


/*
    BUSCA PELO MVP INFORMADA, COMPARADO-SE O NOME DO MVP COM AQUELES QUE ESTAO NA LISTA EM MEMORIA PRINCIPAL, 
    E TODA VEZ QUE UM MVP EH ENCONTRADA, SEU RRN EH ARMAZENADO NO VETOR DE RRNS; POR FIM, RETORNAMOS A QUANTIDADE DE REGISTROS ENCONTRADOS,
    ATRAVES DA VARIAVEL ACHOU
*/
int buscarMvpResultado(IPRIMARY *listaIndicePrimario, IMVP *listaIndiceMVP, int totalRegistros, char *strBuscaMVP, int **vetorRrnMvps){
    int i=0, achouMVP = 0;
    
    *vetorRrnMvps = (int*) malloc(sizeof(int) * (achouMVP+1) );
    
    for ( ; i < totalRegistros; i++){
        if ( strcmp( (listaIndiceMVP + i)->iMVP, strBuscaMVP ) == 0 ){
            *vetorRrnMvps = (int*) realloc(*vetorRrnMvps, sizeof(int) * (achouMVP+1) );
            (*vetorRrnMvps)[achouMVP] = buscarCodigoIndicePrimario( listaIndicePrimario, totalRegistros, (listaIndiceMVP + i)->codigo );
            achouMVP += ( (*vetorRrnMvps)[achouMVP] == -1) ? 0 : 1;
        }
    }

    return achouMVP;
}

//------------------------------------------------FUNCAO PARA CADASTRAR REGISTROS ---------------------------------------------------

/*
    FUNCAO PARA CADASTRAR UM REGISTRO
    APOS LER TODAS AS ENTRADAS, CONSTRUIMOS O CODIGO DO REGISTRO E VERIFICAMOS SE O MESMO NAO EXISTE
    CASO NAO EXISTA, PROSSEGUIMOS COM A INSERCAO DO MESMO NO ARQUIVO DE DADOS E NAS LISTAS QUE ESTAO
    EM MEMORIA

*/


void cadastrarRegistro(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, IWINNER **listaIndiceWinner, int *totalRegistros){
	int bytes=0, i=0, contaLinha=0, existeChavePrimaria=0;
    FILE *matchesFile;
    MATCHE novaPartida;
    
    getchar();
	do{

        scanf("%[^\n]",novaPartida.equipeAzul); 
        getchar(); 

    }while(checkarNomeEquipeMVP(novaPartida.equipeAzul));

    do{

        scanf("%[^\n]",novaPartida.equipeVermelha); 
        getchar();

    }while(checkarNomeEquipeMVP(novaPartida.equipeVermelha));

    do{

        scanf("%[^\n]",novaPartida.data);
        getchar();

    }while(checkarData(novaPartida.data));
	
    do{

        scanf("%[^\n]",novaPartida.duracao); 
        getchar();

    }while( checkarDuracao(novaPartida.duracao) );
	
    do{
        
        scanf("%[^\n]",novaPartida.equipeVencedora); 
        getchar();

    }while( checkarNomeEquipeMVP(novaPartida.equipeVencedora) || 
            checkarVencedor(novaPartida.equipeVencedora, novaPartida.equipeAzul, novaPartida.equipeVermelha) );
	
    do{

        scanf("%[^\n]",novaPartida.placarAzul); 
        getchar();

    }while( checkarPlacar(novaPartida.placarAzul) );
	
    do{

        scanf("%[^\n]",novaPartida.placarVermelha); 
        getchar();
    
    }while( checkarPlacar(novaPartida.placarVermelha) );

	do{

        scanf("%[^\n]",novaPartida.apelidoMVP); 
        getchar();
    
    }while( checkarNomeEquipeMVP(novaPartida.apelidoMVP) );

    /*MONTAMOS A CHAVE PRIMARIA (CODIGO)*/
    novaPartida.codigo[0] = toupper(novaPartida.equipeAzul[0]);
    novaPartida.codigo[1] = toupper(novaPartida.equipeVermelha[0]);
    novaPartida.codigo[2] = toupper(novaPartida.apelidoMVP[0]);
    novaPartida.codigo[3] = toupper(novaPartida.apelidoMVP[1]);
    novaPartida.codigo[4] = novaPartida.data[0];
    novaPartida.codigo[5] = novaPartida.data[1];
    novaPartida.codigo[6] = novaPartida.data[3];
    novaPartida.codigo[7] = novaPartida.data[4];
    novaPartida.codigo[8] = '\0';

    if(*totalRegistros != 0){
        existeChavePrimaria = buscarCodigoIndicePrimario(*listaIndicePrimario, *totalRegistros, novaPartida.codigo);
    }
    else{
        existeChavePrimaria = -1;
    }

    if( existeChavePrimaria == -1 ){

        *listaIndicePrimario = (IPRIMARY*) realloc(*listaIndicePrimario, sizeof(IPRIMARY) * (*totalRegistros + 1));
        *listaIndiceMVP = (IMVP*) realloc(*listaIndiceMVP, sizeof(IMVP) * (*totalRegistros + 1) );
        *listaIndiceWinner = (IWINNER*) realloc(*listaIndiceWinner, sizeof(IWINNER) * (*totalRegistros + 1) );

        strcpy((*listaIndiceMVP + (*totalRegistros))->iMVP, novaPartida.apelidoMVP);
        strcpy((*listaIndiceMVP + (*totalRegistros))->codigo, novaPartida.codigo);
        
        strcpy((*listaIndiceWinner + (*totalRegistros))->iEquipeVencedora, novaPartida.equipeVencedora);
        strcpy((*listaIndiceWinner + (*totalRegistros))->codigo, novaPartida.codigo);
        
        strcpy( (*listaIndicePrimario + *totalRegistros)->codigo, novaPartida.codigo);
        (*listaIndicePrimario + *totalRegistros)->rrn = ++(*totalRegistros);

        ordenarIndices( listaIndicePrimario, listaIndiceWinner, listaIndiceMVP, *totalRegistros);

        if( ( matchesFile = fopen( DADOS_FILE, "a+" ) ) ){

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

            for(i = 0; i < MAX_REGISTRO - bytes; i++){
                fprintf(matchesFile, "#");
            }

            fclose(matchesFile);
        }

	}else{
        printf("ERRO: Já existe um registro com a chave primária %s.\n",novaPartida.codigo);
    }

}
//------------------------------------------------FUNCOES PARA CARREGAR OS INDICES NA MEMORIA ---------------------------------------------------


/*
    CARREGA O INDICE NA MEMORIA, ATRAVES DA LEITURA DO SEU ARQUIVO DE INDICE
    TAMBEM FAZ A CONFERENCIA DA FLAG QUE EH POSICIONADA NA PRIMEIRA LINHA DO ARQUIVO DE INDICE
    APOS FAZER A LEITURA DOS REGISTROS NO ARQUIVO DE INDICE, A FLAG EH ALTERADA PARA 0.
    ESSA FLAG SOH VOLTARA PARA 1 QUANDO ATUALIZARMOS OS INDICES OU VERIFICARMOS QUE NOSSO
    ARQUIVO ESTA DESATUALIZADO
*/
int carregarIndicePrimario(IPRIMARY **listaIndicePrimario, int *totalRegistros){
    FILE *iprimaryFile;
    char auxStr[MAX_INDICE], *token, ch, barraN;
    int i=0;
    if(*totalRegistros > 0){

        *listaIndicePrimario = (IPRIMARY *) malloc( sizeof(IPRIMARY) * *totalRegistros);

        if( ( iprimaryFile = fopen( PRIMARY_FILE, "r+" ) ) ){
            
            ch = fgetc(iprimaryFile);
            barraN = fgetc(iprimaryFile);

            if(ch == '1'){
                while( i < *totalRegistros ){
                    fgets(auxStr, MAX_INDICE, iprimaryFile);
                    if ( (strcmp(auxStr,"\n") != 0) ){
                        token = strtok(auxStr, "@");  //USADO COMO TOKEN PRA SEPARAR O CODIGO DO RRN, DAI USAMOS O STRTOK
                        strcpy( (*listaIndicePrimario + i)->codigo, token);
                        token = strtok(NULL, "@"); //USADO COMO TOKEN PRA SEPARAR O CODIGO DO RRN, DAI USAMOS O STRTOK
                        (*listaIndicePrimario + i)->rrn = atoi(token);
                        i++;
                    }
                }
                fseek(iprimaryFile,0,SEEK_SET);
                fprintf(iprimaryFile, "%c\n", '0' );
                fclose(iprimaryFile);
                return 0;

            }
            else{
                fclose(iprimaryFile);
                return -1;
            }

            
        }
    }
    
    return -1;
}


/*
    CARREGA O INDICE NA MEMORIA, ATRAVES DA LEITURA DO SEU ARQUIVO DE INDICE
    A MESMA IDEIA QUE FOI UTILIZADA NO INDICE ANTERIOR, EH UTILIZADA AQUI
*/
int carregarIndiceMVP(IMVP **listaIndiceMVP, int *totalRegistros){
    FILE *iMVPFile;
    char auxStr[MAX_INDICE], *token, ch, barraN;
    int i=0;

    if(*totalRegistros > 0){

        *listaIndiceMVP = (IMVP *) malloc( sizeof(IMVP) * *totalRegistros );//Aloca o espaço para os dados do arquivo de índice.

        if( ( iMVPFile = fopen( MVP_FILE, "r+" ) ) ){

            ch = fgetc(iMVPFile);
            barraN = fgetc(iMVPFile);            

            if(ch == '1'){
                while( i < *totalRegistros ){
                    fgets(auxStr, MAX_INDICE, iMVPFile);
                    if ( (strcmp(auxStr,"\n") != 0) ){
                        token = strtok(auxStr, "@");  
                        strcpy( (*listaIndiceMVP + i)->iMVP, token);//USADO COMO TOKEN PRA SEPARAR O MVP DO RRN, DAI USAMOS O STRTOK
                        token = strtok(NULL, "@");
                        strcpy( (*listaIndiceMVP + i)->codigo, token );//USADO COMO TOKEN PRA SEPARAR O CODIGO DO RRN, DAI USAMOS O STRTOK
                        i++;
                    }
                }
                fseek(iMVPFile,0,SEEK_SET);
                fprintf(iMVPFile, "%c\n", '0');
                fclose(iMVPFile);
                return 0;
            }
            else{
                fclose(iMVPFile);
                return -1;
            }
        }
    }

    return -1;
 
}
/*
    CARREGA O INDICE NA MEMORIA, ATRAVES DA LEITURA DO SEU ARQUIVO DE INDICE
    A MESMA IDEIA QUE FOI UTILIZADA NO INDICE ANTERIOR, EH UTILIZADA AQUI

*/
int carregarIndiceWinner(IWINNER **listaIndiceWinner, int *totalRegistros){
    FILE *winnerFile;
    char auxStr[MAX_INDICE], *token, ch, barraN;
    int i=0;

    winnerFile = fopen(WINNER_FILE, "r+");

    if(*totalRegistros > 0){

        *listaIndiceWinner = (IWINNER *) malloc( sizeof(IWINNER) * *totalRegistros );//Aloca o espaço para os dados do arquivo de índice.

        if(winnerFile){
            
            ch = fgetc(winnerFile);
            barraN = fgetc(winnerFile);

            if(ch == '1'){

                while( i < *totalRegistros ){
                    fgets(auxStr, MAX_INDICE, winnerFile);
                    if ( (strcmp(auxStr,"\n") != 0) ){
                        token = strtok(auxStr, "@"); //USADO COMO TOKEN PRA SEPARAR O MVP DO RRN, DAI USAMOS O STRTOK
                        strcpy( (*listaIndiceWinner + i)->iEquipeVencedora, token);
                        token = strtok(NULL, "@"); //USADO COMO TOKEN PRA SEPARAR O MVP DO RRN, DAI USAMOS O STRTOK
                        strcpy( (*listaIndiceWinner + i)->codigo, token );
                        i++;
                    }
                }

                fseek(winnerFile,0,SEEK_SET);
                fprintf(winnerFile, "%c\n", '0');
                fclose(winnerFile);
                return 0;

            }
            else{
                fclose(winnerFile);
                return -1;
            }

        }
    }
    
    return -1;
}


//------------------------------------------------FUNCOES PARA CHECAGEM DE VALORES---------------------------------------------------

/*FUNCOES PARA VALIDACAO DE CAMPOS*/

int checkarNomeEquipeMVP(char *nome){

    if( (strlen(nome) > 38) || (strlen(nome) < 2) ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else{
        return 0;
    }
    
}

/*FUNCOES PARA VALIDACAO DE CAMPOS*/


int checkarData(char *data){

    if( (data[0] - '0') < 0 || (data[0] - '0') > 3){ // VERIFICA PRIMEIRO DIGITO
        printf("Campo inválido! Informe novamente:");
        return 1;
    } 
    if((data[0] - '0' ) == 3 && (data[1] - '0') > 1){ 
        printf("Campo inválido! Informe novamente:");
        return 1;   
    }
    if( ( (data[0] - '0') == 0 && (data[1] - '0') == 0 ) || ((data[1] - '0') < 0 || (data[1] - '0') > 9)  ){ // VERIFICA SEGUNDO DIGITO
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( data[2] != '/' ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (data[3] - '0') < 0 || (data[3] - '0') > 1){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if(  ( (data[3] - '0') == 1 && (data[4] - '0') > 2) || ( (data[3] - '0') == 0  && (data[4] - '0') == 0 ) || ( (data[4] - '0') < 0 || (data[4] - '0') > 9) 
           || ( (data[3] - '0') == 3 && (data[4] - '0') > 1) ||  ( (data[4] - '0') < 0 || (data[4] - '0') > 9)   ){

        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( data[5] != '/'  ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (data[6] - '0') != 2 ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (data[7] - '0') != 0 ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (data[8] - '0') != 1 ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (data[9] - '0') < 1 || (data[9] - '0') > 5  ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else{
        return 0;
    }

}

/*FUNCOES PARA VALIDACAO DE CAMPOS*/


int checkarDuracao(char *duracao){

    if( (duracao[0] - '0') < 0 || (duracao[0] - '0') > 9  ){ // VERIFICA PRIMEIRO DIGITO
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (duracao[1] - '0') < 0 || (duracao[1] - '0') > 9){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if(duracao[2] != ':'){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if((duracao[3] - '0') < 0 || (duracao[3] - '0') > 5){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (duracao[4] - '0') < 0 || (duracao[4] - '0') > 9 ){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if(duracao[5]!= '\0'){
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else{
        return 0;
    
    }

}

/*FUNCOES PARA VALIDACAO DE CAMPOS*/


int checkarDuracao1(char *duracao){

    if( (duracao[0] - '0') < 0 || (duracao[0] - '0') > 9  ){ // VERIFICA PRIMEIRO DIGITO
        printf("Campo inválido!");
        return 1;
    }
    else if( (duracao[1] - '0') < 0 || (duracao[1] - '0') > 9  ){
        printf("Campo inválido!");
        return 1;
    }
    else if(duracao[2] != ':'){
        printf("Campo inválido!");
        return 1;
    }
    else if((duracao[3] - '0') < 0 || (duracao[3] - '0') > 5){
        printf("Campo inválido!");
        return 1;
    }
    else if((duracao[4] - '0') < 0 || (duracao[4] - '0') > 9){
        printf("Campo inválido!");
        return 1;
    }
    else if(duracao[5]!= '\0'){
        printf("Campo inválido!");
        return 1;
    }
    else{
        return 0;
    
    }

}
/*FUNCOES PARA VALIDACAO DE CAMPOS*/


int checkarPlacar(char *placar){
    if( (placar[0] - '0') < 0 || (placar[0] - '0') > 9  ){ // VERIFICA PRIMEIRO DIGITO
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( (placar[1] - '0') < 0 || (placar[1] - '0') > 9  ){ // VERIFICA PRIMEIRO DIGITO
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else if( placar[2] != '\0'){ // VERIFICA PRIMEIRO DIGITO
        printf("Campo inválido! Informe novamente:");
        return 1;
    }
    else{
        return 0;
    }
}

/*FUNCOES PARA VALIDACAO DE CAMPOS*/


int checkarVencedor(char *equipeVencedora, char *equipeAzul, char *equipeVermelha){
    
    if( (strcmp(equipeVencedora,equipeAzul) == 0) || (strcmp(equipeVencedora,equipeVermelha) == 0) ){
        return 0;
    }

    printf("Campo inválido! Informe novamente:");
    return 1;

}

//------------------------------------------------FUNCOES COMPARE PARA O QUICKSORT---------------------------------------------------

/*FUNCOES DE COMPARACAO DE CHAR* PARA O QUICKSORT */


int compararIndicePrimario(const void *str1, const void *str2){
    return strcmp( ((IPRIMARY*)str1)->codigo, ((IPRIMARY*)str2)->codigo);
}


int compararIndiceMVP(const void *str1, const void *str2){
    return strcmp( ((IMVP*)str1)->iMVP, ((IMVP*)str2)->iMVP);
}


int compararIndiceWinner(const void *str1, const void *str2){
    return strcmp( ((IWINNER*)str1)->iEquipeVencedora, ((IWINNER*)str2)->iEquipeVencedora);
}


int compararBuscaEquipeMVP(const void *str1, const void *str2){
    return strcmp( ((MATCHE*)str1)->codigo, ((MATCHE*)str2)->codigo);
}

//-----------------------------------------------FUNCOES PARA IMPRIMIR O RESULTADO DA BUSCA-------------------------------------------


/*TOKENIZA O CODIGO PRA IMPRESSAO NA TELA*/
void imprimirBuscaCodigo(int rrnCodigo){
    FILE *dataFile;
    char auxStr[MAX_REGISTRO], *tokenAux;

    if( ( dataFile = fopen( DADOS_FILE,"r" ) ) ){
        fseek(dataFile, (rrnCodigo-1)*MAX_REGISTRO, SEEK_SET);

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
        printf("%s\n\n", tokenAux);

        fclose(dataFile);
    }
}


/*ESSA FUNCAO TOKENIZA CADA REGISTRO ENCONTRADO, ARMAZENA ELE NUMA STRUCT, E DEPOIS ENVIA ESSE REGISTRO PRA OUTRA FUNCAO ORDENAR E IMPRIMIR*/
void imprimirBuscaEquipeMVP( int resultadoBusca, int **vetorRrn){
    int i=0;
    FILE *dataFile;
    MATCHE *dadosBuscados = NULL;
    char auxStr[MAX_REGISTRO], *tokenAux;

    

    if( ( dataFile = fopen( DADOS_FILE, "r" ) ) ){

        dadosBuscados = (MATCHE *) malloc( sizeof(MATCHE) * resultadoBusca);

        for( ; i < resultadoBusca ; i++){

            fseek(dataFile, ( (*vetorRrn)[i] - 1 ) * MAX_REGISTRO, SEEK_SET);
            
            fgets(auxStr,MAX_REGISTRO,dataFile);

            tokenAux = strtok(auxStr,"@");
            strcpy( (dadosBuscados + i)->codigo, tokenAux );

            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->equipeAzul, tokenAux );

            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->equipeVermelha, tokenAux );

            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->data , tokenAux );
            
            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->duracao, tokenAux );
            
            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->equipeVencedora, tokenAux );

            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->placarAzul, tokenAux );
            
            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->placarVermelha, tokenAux );
            
            tokenAux = strtok(NULL,"@");
            strcpy( (dadosBuscados + i)->apelidoMVP, tokenAux );

        }

        fclose(dataFile);
        listarBuscaEquipeMVP(&dadosBuscados, resultadoBusca);

    }
    free(dadosBuscados);
}


//------------------------------------------------FUNCOES PARA LIBERAR REGISTROS ---------------------------------------------------
void liberarArquivoDadosIndice(IPRIMARY **listaIndicePrimario, IWINNER **listaIndiceWinner, IMVP **listaIndiceMVP, int *totalRegistros){
    char carregarRegistro[MAX_REGISTRO],ch;
    int newRRN=0, j=0, i=0, updateDataFileAndIndexes=0;

    IPRIMARY *auxCopyPrimary;
    IWINNER *auxCopyWinner;
    IMVP *auxCopyMVP;
    FILE *dataFile, *tempDataFile;

    dataFile = fopen(DADOS_FILE, "r+");
    tempDataFile = fopen("tempDataFile.txt", "a+");

    if(dataFile && tempDataFile){ 
        
        for ( ; i < *totalRegistros; i++){
            
            fseek( dataFile, i * MAX_REGISTRO, SEEK_SET );
            fgets(carregarRegistro, MAX_REGISTRO, dataFile);

            if( (carregarRegistro[0] != '*') && (carregarRegistro[1] != '|') ){
                
                for(j=0; j < 192; j++){
                    fputc(carregarRegistro[j], tempDataFile);
                }
                
                newRRN++;

            }
            else{
                updateDataFileAndIndexes++;
            }

        }
        
        *totalRegistros = newRRN;

        fclose(dataFile);
        
        if(updateDataFileAndIndexes != 0){
            fclose(tempDataFile);
            rename("tempDataFile.txt", "matches.dat");
            /*if( ( dataFile = fopen(DADOS_FILE,"w") ) && ( tempDataFile = fopen("tempDataFile.txt","r")  ) ) {
      
                for(i = 0; i < newRRN; i++){
                    
                    fseek(tempDataFile, i * MAX_REGISTRO, SEEK_SET);
                    fgets(carregarRegistro, MAX_REGISTRO, tempDataFile);
                    
                    for(j=0; j < 192; j++){
                        ch = carregarRegistro[j];
                        fputc(ch, dataFile);
                    }

                }

            }
            fclose(dataFile);*/
        }

        if(updateDataFileAndIndexes != 0){

            auxCopyPrimary = (IPRIMARY*) malloc( sizeof(IPRIMARY) * *totalRegistros);
            auxCopyWinner = (IWINNER*) malloc( sizeof(IWINNER) * *totalRegistros);
            auxCopyMVP = (IMVP*) malloc( sizeof(IMVP) * *totalRegistros);

            refazerIndices( listaIndicePrimario, listaIndiceMVP, listaIndiceWinner, *totalRegistros);
            ordenarIndices( listaIndicePrimario, listaIndiceWinner, listaIndiceMVP, *totalRegistros);
        }

        fclose(tempDataFile);
        remove("tempDataFile.txt");
        
    }

}


//---------------------------------------------------LISTAR REGISTROS---------------------------------------------------------------------


/*FUNCAO PRA RPINTAR NA TELA, EH USADO NO CASO DA BUSCA POR EQUIPES OU MVP*/
void listarBuscaEquipeMVP(MATCHE **resultadoBuscaEquipeMVP, int totalRegistros){
    int i=0;

    ordenarBuscaEquipeMVP(resultadoBuscaEquipeMVP, totalRegistros);
    
    for ( ; i < totalRegistros; i++){
        printf("\n%s\n", (*resultadoBuscaEquipeMVP + i)->codigo);
        
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->equipeAzul);
       
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->equipeVermelha); 

        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->data);
       
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->duracao);
       
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->equipeVencedora);
        
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->placarAzul);
        
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->placarVermelha);
       
        printf("%s\n", (*resultadoBuscaEquipeMVP + i)->apelidoMVP);
    }

}


/*IMPRIMIMOS A LISTA DAS CHAVES PRIMARIAS, DESDE QUE SEU RRN SEJA DIFERENTE DE -1*/
void listarPorCodigo(IPRIMARY **listaIndicePrimario, int *totalRegistros){
    int i=0;

    ordenarIndicePrimario(listaIndicePrimario, *totalRegistros);

    for ( ; i < *totalRegistros; i++){
       
        if( (*listaIndicePrimario + i)->rrn != -1 ){
            imprimirBuscaCodigo((*listaIndicePrimario + i)->rrn );
        }
    }
}

/*IMPRIMIMOS A LISTA DOS MVPS */
void listarPorMVP(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, int *totalRegistros){
    int i=0, resultadoBuscaCodigo;

    ordenarIndiceMVP(listaIndiceMVP, *totalRegistros);
    
    for ( ; i < *totalRegistros; i++){

        resultadoBuscaCodigo = buscarCodigoIndicePrimario( *listaIndicePrimario, *totalRegistros,   (*listaIndiceMVP + i)->codigo );

        if(resultadoBuscaCodigo == -1){
            printf("Registro não encontrado!\n");
        }
        else{
            imprimirBuscaCodigo(resultadoBuscaCodigo);
        }
    }
}

/*IMPRIMIMOS A LISTA DAS EQUIPES VENCEDORAS*/
void listarPorWinner(IPRIMARY **listaIndicePrimario, IWINNER **listaIndiceWinner, int *totalRegistros){
    int i = 0, resultadoBuscaCodigo;

    ordenarIndiceWinner(listaIndiceWinner, *totalRegistros);
    
    for ( ; i < *totalRegistros; i++){

        resultadoBuscaCodigo = buscarCodigoIndicePrimario( *listaIndicePrimario, *totalRegistros,   (*listaIndiceWinner + i)->codigo );

        if(resultadoBuscaCodigo == -1){
            printf("Registro não encontrado!\n");
        }
        else{
            imprimirBuscaCodigo(resultadoBuscaCodigo);
        }
    }
}


//---------------------------------------------------------ORDENAR REGISTROS---------------------------------------------------------------

/*FUNCOES PRA ORDENCAO USANDO A FUNCAO QSORT DO C*/

void ordenarBuscaEquipeMVP(MATCHE **equipesBuscadas, int totalRegistros){
    qsort(*equipesBuscadas, totalRegistros, sizeof(MATCHE), compararBuscaEquipeMVP);
}

void ordenarIndices(IPRIMARY **listaIndicePrimario,  IWINNER **listaIndiceWinner, IMVP **listaIndiceMVP, int totalRegistros ){

    ordenarIndicePrimario(listaIndicePrimario,  totalRegistros);
    ordenarIndiceMVP(listaIndiceMVP,  totalRegistros);
    ordenarIndiceWinner(listaIndiceWinner,  totalRegistros);

}

void ordenarIndicePrimario(IPRIMARY **listaIndicePrimario, int totalRegistros){
    qsort(*listaIndicePrimario, totalRegistros, sizeof(IPRIMARY), compararIndicePrimario);
}


void ordenarIndiceMVP(IMVP **listaIndiceMVP, int totalRegistros){
    qsort(*listaIndiceMVP, totalRegistros, sizeof(IMVP), compararIndiceMVP);
}


void ordenarIndiceWinner(IWINNER **listaIndiceWinner, int totalRegistros){
    qsort(*listaIndiceWinner, totalRegistros, sizeof(IWINNER), compararIndiceWinner);
}


//---------------------------------------------------------FUNCAO PARA REMOVER REGISTROS---------------------------------------------------------------
void refazerIndices(IPRIMARY **listaIndicePrimario, IMVP **listaIndiceMVP, IWINNER **listaIndiceWinner, int totalRegistros){
    int i = 0, j = 0;
    char *tokenEquipe, *tokenPK, *tokenMVP, *tokenGeral, aux[MAX_REGISTRO];
    FILE *dataFile;

    //printf("refazerIndices\n");
    
    if( ( dataFile = fopen( DADOS_FILE, "r+" ) ) ){
        //printf("Abriu data file\n");
        for (j=0 ; j < totalRegistros; j++){

            fseek(dataFile, j * MAX_REGISTRO, SEEK_SET );
            fgets(aux, MAX_REGISTRO, dataFile);
            //printf("Resultado fgets [%s]\n", aux);
            tokenPK = strtok(aux, "@");   //pega a chave primaria, na posicao 0
            
            strcpy( (*listaIndicePrimario + j)->codigo, tokenPK);
            (*listaIndicePrimario + j)->rrn =  j+1;

            for(i=0 ; i < 9 ;i++){
                
                if(i == 4){
                    tokenEquipe = strtok(NULL, "@");   //pega a equipe, caso seja o token na posicao 4
                }
                else if(i == 8){
                    tokenGeral = strtok(NULL,"@"); //pega a equipe, caso seja o token na posicao 8
                }
                else{
                    tokenMVP = strtok(NULL,"@"); //pega qq coisa caso contrario
                }

            }
            
            strcpy((*listaIndiceWinner + j)->iEquipeVencedora, tokenEquipe);
            strcpy((*listaIndiceWinner + j)->codigo, tokenPK);  

            strcpy((*listaIndiceMVP + j)->iMVP, tokenMVP );
            strcpy((*listaIndiceMVP + j)->codigo, tokenPK );  

            //printf("Token PK[%s] Token RRN [%d]\n", (*listaIndicePrimario + j)->codigo, (*listaIndicePrimario + j)->rrn  );
            //printf("Token Equipe[%s] Token Codigo [%s]\n", (*listaIndiceWinner + j)->iEquipeVencedora, (*listaIndiceWinner + j)->codigo  );
            //printf("Token MVP[%s] Token Codigo[%s]\n", (*listaIndiceMVP + j)->iMVP, (*listaIndiceMVP + j)->codigo );

        } 
    }    
    fclose(dataFile);
}

//---------------------------------------------------------FUNCAO PARA REMOVER REGISTROS---------------------------------------------------------------


void removerRegistro(int rrnRegistroRemover, char *valorChavePK, IPRIMARY **listaIndicePrimario, int *totalRegistros){
    int i=0, contArrobas=0, j=0, flag=1;
    char carregarRegistro[MAX_REGISTRO];
    FILE *dataFile;

    if( (dataFile = fopen(DADOS_FILE, "r+" ) ) ){
        
        fseek( dataFile, (rrnRegistroRemover - 1) * MAX_REGISTRO, SEEK_SET );        

        fputc('*', dataFile);
        fputc('|', dataFile);
        
        for( ; i < *totalRegistros; i++ ){

            if( ( strcmp( (*listaIndicePrimario + i)->codigo,  valorChavePK ) == 0 ) ){
                (*listaIndicePrimario + i)->rrn = -1;
            }

        }

        fclose(dataFile);
    }
   
}