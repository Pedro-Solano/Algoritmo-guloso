# Conceito abordado: algoritmos gulosos X programação dinâmica.

## O problema:

Um grupo de viajantes se organiza para fazer uma viagem visitando várias ilhas ao redor do mundo. Dado que o orçamento da viagem é limitado, eles estabeleceram pontos para cada ilha, para indicar o quanto gostariam de visitar determinada ilha. Também calcularam o custo diário para se permanecer em cada ilha (considerando transporte, acomodação e alimentação). Feito isso, eles decidiram analisar dois tipos de roteiro, conforme o orçamento disponível:

  Roteiro 1 - Prioriza a maior pontuação possível de se obter ao escolher um conjunto de ilhas, msmo que ocorra repetição (permanecendo na mesma ilha por mais de um dia). 
  Roteiro 2 - Prioriza a maior pontuação possível, sem repetir nenhuma ilha.
  
O objetivo deste trabalho é, dados dois valores inteiros N e M, que representam, respectivamente, o orçamento disponível e o número máximo de ilhas com seus custos e pontuações por dia, desenvolver duas soluções:

  1. Utilizando um algoritmo guloso, determinar: 
  (a) a maior pontuação possível em um roteiro no qual pode haver repetições de ilhas (ficar mais de um dia na mesma ilha), e;
  (b) a quantidade de dias que durará a viagem. O tempo de execução do seu algoritmo para esse problema não deve ser superior a O(m log m).
  
  2. Utilizando programmação dinâmica, determinar:
  (a) a maior pontuação possível em um roteiro no qual sem repetições de ilhas, e;
  (b) a quantidade de dias que durará a viagem. O tempo de execução do seu algoritmo para esse problema não deve ser superior O(n * m).

## Entrada:

As informações sobre o roteiro de viagem são informadas por meio de um arquivo .txt.
Na primeira linha são dados dois inteiros N e M, que representam o orçamento disponível e a quantidade máxima de ilhas, respectivamente. Nas próximas M linhas, são dados dois inteiros: o primeiro deles, D, representa o custo diário de cada ilha; o segundo, P, representa a pontuação atribuída pelos viajantes àquela ilha.

## Saída:

A saída do programa possui 2 linhas, que serão impresssas na tela.
Na primeira, imprimi-se a pontuação total para o problema 1 (que pode repetir ilhas) e a quantidade de dias que durará a viagem. Na segunda linha, imprime-se a pontuação total para o problema 2 (que não pode repetir ilhas) e a quantidade de dias que durará a viagem.

## Documentação:

