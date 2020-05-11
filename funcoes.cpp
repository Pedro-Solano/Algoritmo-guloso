#include <iostream>	
#include <fstream>	
#include "funcoes.h"

using std::cout;
using std::endl;


//le o arquivo de entrada para obter o numero de ilhas e valor disponivel
void le_viagem(char* arq, int* ilhas, int* valor){	

    FILE *fp = fopen(arq,"r");			//ponteiro para o arquivo de entrada
    if(!fp) {					//avisa ao usuario que nao foi possivel abrir o arquivo
        printf("\aERRO na leitura do arquivo.\n");
        printf("Finalizando...\n");
    }
    else{					//armazena o numero de dias e valor disponivel
      fscanf(fp,"%d",valor);			
      fscanf(fp,"%d",ilhas);
    }
    fclose(fp);					//fecha o arquivo
}


//le o arquivo de entrada para preencher os vetores de custos e pontos das ilhas
void preenche_ilhas(char* arq, int ilhas, int *cust, int *pt){

    int aux;					//utilizada no loop de leitura do arquivo
    FILE *fp = fopen(arq,"r");			//ponteiro para o arquivo de entrada
    if(!fp) {					//avisa ao usuario que nao foi possivel abrir o arquivo
        printf("\aERRO na leitura do arquivo.\n");
        printf("Finalizando...\n");
    }
    else
    {
      fscanf(fp,"%d",&aux);           		//saltar as 2 primeiras posições
      fscanf(fp,"%d",&aux); 

      for (aux=0;aux<ilhas;aux++){		//preenche os vetores de custos e pontos das ilhas

        fscanf(fp,"%d",&cust[aux]);
        fscanf(fp,"%d",&pt[aux]);
      }
    }
    fclose(fp);					//fecha o arquivo
}


/*Faz o merge dos subvetores de cxb e a movimentacao correspondente dos elementos dos vetores c e b. O primeiro subvetor e cxb[l...m]
e o segundo subvetor e cxb[m+1...r]*/
void merge(float *cxb, int l, int m, int r, int *c, int *b)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // criacao de vetores temporarios 
    float Lcb[n1], Rcb[n2];			//subvetores esquerdo e direito do vetor de custo-beneficio
    int Lc[n1], Rc[n2];				//subvetores esquerdo e direito do vetor de custos
    int Lb[n1], Rb[n2];				//subvetores esquerdo e direito do vetor de beneficios

    // Preenchimento dos subvetores do lado esquerdo
    for (i = 0; i < n1; i++){
        Lcb[i] = cxb[l + i];
        Lc[i] = c[l + i];
        Lb[i] = b[l + i];
    }
    // Preenchimento dos subvetores do lado direito
    for (j = 0; j < n2; j++){
        Rcb[j] = cxb[m + 1+ j];
        Rc[j] = c[m + 1+ j];
        Rb[j] = b[m + 1+ j];
    }
    
    i = 0; 				// indice inicial do subvetor esquerdo
    j = 0; 				// indice inicial do subvetor direito
    k = l; 				// indice inicialdo vetor resultante

    /* Faz o merge dos subvetores de cxb para formar o vetor cxb ordenado. Tambem faz a movimentacao correspondente dos elementos dos vetores c[] e b[]*/

    while (i < n1 && j < n2)
    {
        if (Lcb[i] <= Rcb[j])		
        {
            cxb[k] = Lcb[i];		
            c[k] = Lc[i];
            b[k] = Lb[i];
            i++;
        }
        else
        {
            cxb[k] = Rcb[j];
            c[k] = Rc[j];
            b[k] = Rb[j];
            j++;
        }
        k++;
    }

    // Copia os elementos remanescentes do vetores esquerdos, se existirem
    while (i < n1)
    {
        cxb[k] = Lcb[i];
        c[k] = Lc[i];
        b[k] = Lb[i];
        i++;
        k++;
    }

    // Copia os elementos remanescentes do vetores direitos, se existirem
    while (j < n2)
    {
        cxb[k] = Rcb[j];
        c[k] = Rc[j];
        b[k] = Rb[j];
        j++;
        k++;
    }
}


/* Realiza a ordenacao merge sort, sendo l o indice esquero e r o indice direito do subvetor a ser ordenado, cxb.*/
void mergeSort(float *cXb, int l, int r, int *custos, int *pontos)
{
    if (l < r)
    {
        int m = l+(r-l)/2;			//determina o indice que divide o vetor ao meio	

        // faz a recursao com os subvetores
        mergeSort(cXb, l, m, custos, pontos);
        mergeSort(cXb, m+1, r, custos, pontos);

        merge(cXb, l, m, r, custos, pontos);
    }
}

//calcula a razao entre o custo e os pontos de cada ilha e preeche o vetor
void preenche_cXb(int i, float *cXb, int *c, int *b){

    for (int aux=0;aux<i;aux++){
      cXb[aux] = (float) c[aux]/b[aux];
    }
}


/* Faz a selecao das ilhas de forma gulosa, a partir da proporcao custo por pontos de cada ilha. Exibe os resultados da pontuacao e numero de dias na tela*/
void guloso(int saldo, int ilhas, int *custo, int *pts){

    int i=0;
    int pontuacao=0;
    int n_dias=0;
    float *custoXbeneficio=(float*)malloc(ilhas*sizeof(int));	

    preenche_cXb(ilhas,custoXbeneficio,custo,pts);

    mergeSort(custoXbeneficio, 0, ilhas-1, custo, pts);

    while (saldo>0 && i<ilhas){				//enquanto houver saldo disponivel
      if ((saldo-custo[i])>-1){				//verifica se o saldo e suficiente para pagar um dia na ilha atual
        saldo-=custo[i];				//decrementa o custo da ilha do saldo
        pontuacao+=pts[i];				//incrementa a pontuacao com os pontos da ilha
        ++n_dias;					//incrementa o numero de dias
      }else{
        ++i;						//avanca para a proxima ilha
      }
    }
    cout<<pontuacao<<" "<<n_dias<<endl;	
    free(custoXbeneficio);
}


//retorna o maior valor entre a e b
int max(int a, int b) {				
  return (a > b)? a : b;		
}


/* Faz a selecao das ilhas de de forma dinamica, sem repetir ilhas. Exibe os resultados da pontuacao e numero de dias na tela*/
void dinamico(int orcamento, int *custos, int *val, int n)
{
   int i, o, pontuacao;
   int n_dias=0;
   int k[n+1][orcamento+1];

   // Constroi a tabela k[][]
   for (i = 0; i <= n; i++)
   {
       for (o = 0; o <= orcamento; o++)
       {
           if (i==0 || o==0)
               k[i][o] = 0;						//primeira linha e primeira coluna sao preenchidas com 0
           else if (custos[i-1] <= o)
                 k[i][o] = max(val[i-1] + k[i-1][o-custos[i-1]],  k[i-1][o]);	//verifica os valores ja preenchidos na tabela
           else
                 k[i][o] = k[i-1][o];					//custo da i-esima ilha e maior que o orçamento disponivel					
       }
   }

    pontuacao = k[n][orcamento];

    cout<<pontuacao<<" ";			//imprime na tela a pontuacao obtida

    o = orcamento;

    for (i = n; i > 0 && pontuacao > 0; i--) {

        /*O resultado vem do topo da tabela (k[i-1][o]) ou de (val[i-1] + k[i-1][o-custos[i-1]]). No segundo caso, significa que a ilha foi selecionada*/

        if (pontuacao == k[i - 1][o])
            continue;				//ilha nao foi selecionada

        else {					//ilha foi selecionada
            ++n_dias;				//incrementa a duracao da viagem
            pontuacao = pontuacao - val[i - 1]; //atualiza a pontuacao
            o = o - custos[i - 1];		//atualiza o saldo
        }
    }

    cout<<n_dias<<endl;				//imprime na tela a duracao da viagem
}

