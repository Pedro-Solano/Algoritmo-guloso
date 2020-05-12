#include <stdlib.h>				//malloc, free
#include <string.h> 				//strlen
#include "funcoes.h"
#include <time.h>				//biblioteca utilizada para o calculo do tempo de execucao
#include <iostream>				//printf


int main( int argc, char *argv[ ] )		//funcao principal	
{
	
    clock_t c1, c2;				//variaveis para calcular
    float tempo_guloso, tempo_dinamico;		//o tempo de execucao

    int orcamento,qtde_ilhas;
    int *custos, *pontos;			//vetores que armzenarao informacoes da ilhas
	
    char* arquivo = new char(strlen(argv[1]));
    arquivo=argv[1];				//armazena o nome do arquivo de entrada na variável "arquivo"

    le_viagem(arquivo,&qtde_ilhas,&orcamento);	//leitura das informacoes iniciais da viagem: orcamento e quantidade de ilhas

    custos=(int*)malloc(qtde_ilhas*sizeof(int));	//alocacao dinamica do vetor de custos		
    pontos=(int*)malloc(qtde_ilhas*sizeof(int));	//alocacao dinamica do vetor de pontos

    preenche_ilhas(arquivo,qtde_ilhas,custos,pontos);	//preenche os vetores "custos" e "pontos" a partir da leitura do arquivo de entrada

    c1=clock();						//marcacao de tempo

    guloso(orcamento,qtde_ilhas,custos,pontos);		//calcula a viagem conforme o algoritmo guloso

    c2=clock();						//marcacao de tempo
    tempo_guloso = (c2-c1*1.0)*1000/CLOCKS_PER_SEC;	//calcula o tempo de execucao do algoritmo guloso
    printf("Tempo guloso: %f ms.\n",tempo_guloso);
    c1=clock();						//marcacao de tempo

    dinamico(orcamento,custos,pontos,qtde_ilhas);	//calcula a viagem conforme o algoritmo de programacao dinamica

    c2=clock();
    tempo_dinamico = (c2-c1*1.0)*1000/CLOCKS_PER_SEC;	//calcula o tempo de execucao do algoritmo de programacao dinamica
    printf("Tempo dinamico: %f ms.\n\n",tempo_dinamico);

    free(custos);		//desalocacao de memoria
    free(pontos);		//desalocacao de memoria

    return 0;
}

