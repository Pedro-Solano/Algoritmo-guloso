# Algoritmos gulosos e programação dinâmica

Projeto da disciplina Algoritmos 1, do curso de bacharelado em Sistemas da Informação da Universidade Federal de Minas Gerais - UFMG.

## Objetivo

Esse trabalho visa comparar as complexidades de espaço e de tempo entre um algoritmo guloso e um algoritmo de programação dinâmica.

## O problema:

Um grupo de viajantes planeja fazer uma viagem visitando várias ilhas ao redor do mundo. Dado que o orçamento da viagem é limitado, eles estabeleceram uma pontuação para cada ilha, para indicar o quanto gostariam de visitar cada uma delas. Também calcularam o custo diário para se permanecer em cada ilha (considerando transporte, acomodação e alimentação). Feito isso, eles decidiram analisar dois tipos de roteiro, conforme o orçamento disponível:

  Roteiro 1 - Prioriza a maior pontuação possível de se obter ao escolher um conjunto de ilhas, mesmo que ocorra repetição (permanecendo na mesma ilha por mais de um dia). 
  Roteiro 2 - Prioriza a maior pontuação possível, sem repetir nenhuma ilha, para visitar o máximo de ilhas possível
  
O objetivo deste trabalho é, dados valores inteiros N e M, que representam, respectivamente, o orçamento disponível e o número máximo de ilhas, e seus custos e pontuações por dia, desenvolver duas soluções:

  1. Utilizando um algoritmo guloso, determinar: 
  (a) a maior pontuação possível em um roteiro no qual pode-se permanecer mais de um dia em uma mesma ilha, e;
  (b) a quantidade de dias que durará a viagem. O tempo de execução do seu algoritmo para esse problema não deve ser superior a O(m log m).
  
  2. Utilizando programmação dinâmica, determinar:
  (a) a maior pontuação possível em um roteiro no qual sem repetições de ilhas, e;
  (b) a quantidade de dias que durará a viagem. O tempo de execução do seu algoritmo para esse problema não deve ser superior O(n * m).

## Entrada:

As informações sobre o roteiro de viagem são informadas por meio de um arquivo .txt.
Na primeira linha são dados dois inteiros N e M, que representam o orçamento disponível e a quantidade máxima de ilhas, respectivamente. Nas próximas M linhas, são dados dois inteiros: o primeiro deles, D, representa o custo diário de cada ilha; o segundo, P, representa a pontuação atribuída pelos viajantes àquela ilha.

Por exemplo:

    6000 5      // <Orçamento disponível> <Qtd Ilhas>
    1000 30     // <custo por dia da ilha 1> <pontuação da ilha 1>
    2000 32     // <custo por dia da ilha 2> <pontuação da ilha 2>
    500 4       // <custo por dia da ilha 3> <pontuação da ilha 3>
    5000 90     // <custo por dia da ilha 4> <pontuação da ilha 4>
    2200 45     // <custo por dia da ilha 5> <pontuação da ilha 5>


O arquivo dataset.txt é um exemplo de arquivo de entrada válido.


## Saída:

A saída do programa é impressa na tela e informa o tempo de execução, a pontuação obtida e a duração da viagem para cada um dos algoritmos.

## Documentação:

A análise da solução implementada, a análise da complexidade de tempo e de espaço dos algoritmos guloso e de programação dinâmica e os resultados experimentais, estão registradas no arquivo "documentacao.pdf".

## Compilação:

Deve ser utilizado o comando "make" na linha de comando dentro da pasta onde está armezado o arquivo makefile e os demais arquivos de código. Esse comando irá gerar o executável "ilhas".
O arquivo de entrada deve ser passado como parâmetro para o programa através da linha de comando (e.g., $ ./ilhas dataset.txt).
