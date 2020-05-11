#ifndef FUNCOES_H_INCLUDED		// Garante que nao haja dupla definicao
#define FUNCOES_H_INCLUDED

void le_viagem(char* arq, int* ilhas, int* valor);

void preenche_ilhas(char* arq, int ilhas, int *cust, int *pt);

void merge(float *cxb, int l, int m, int r, int *c, int *b);

void mergeSort(float *cXb, int l, int r, int *custos, int *pontos);

void preenche_cXb(int i, float *cXb, int *c, int *b);

void guloso(int saldo, int ilhas, int *custo, int *pts);

int max(int a, int b);

void dinamico(int orcamento, int *custos, int *val, int n);

#endif // FUNCOES_H_INCLUDED
