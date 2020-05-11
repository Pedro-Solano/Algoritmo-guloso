#include <stdlib.h>				//malloc, free
#include <string.h> 				//strlen
#include "funcoes.h"
//#include <time.h>				//calculo do tempo de execucao
//#include <iostream>				//printf

int main( int argc, char *argv[ ] )		//funcao principal
{
	//clock_t c1, c2;			//variaveis para calcular o
	//float tempo_guloso, tempo_dinamico;	//o tempo de execucao

    int orcamento,qtde_ilhas;
    int *custos, *pontos;
    char* arquivo = new char(strlen(argv[1]));
    arquivo=argv[1];

    le_viagem(arquivo,&qtde_ilhas,&orcamento);

    custos=(int*)malloc(qtde_ilhas*sizeof(int));
    pontos=(int*)malloc(qtde_ilhas*sizeof(int));

    preenche_ilhas(arquivo,qtde_ilhas,custos,pontos);

	//c1=clock();

    guloso(orcamento,qtde_ilhas,custos,pontos);

	//c2=clock();
	//tempo_guloso = (c2-c1*1.0)*1000/CLOCKS_PER_SEC;
	//printf("Tempo guloso: %f ms.\n",tempo_guloso);
	//c1=clock();

    dinamico(orcamento,custos,pontos,qtde_ilhas);

	//c2=clock();
	//tempo_dinamico = (c2-c1*1.0)*1000/CLOCKS_PER_SEC;
	//printf("Tempo dinamico: %f ms.\n",tempo_dinamico);

    free(custos);
    free(pontos);

    return 0;
}
