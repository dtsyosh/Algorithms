#include <stdio.h>
#include <algorithm>
/*
Problema
São dados N pontos em uma circunferência. Você deve escrever um programa que determine quantos triângulos equiláteros distintos podem ser construídos usando esses pontos como vértices.
A figura abaixo ilustra um exemplo; (a) mostra um conjunto de pontos, determinados pelos comprimentos dos arcos de circunferência que têm pontos adjacentes como extremos, e (b) mostra os dois triângulos que podem ser construídos com esses pontos.

Entrada
A entrada contém vários casos de teste.
A primeira linha de cada caso de teste contém um número inteiro N ( 3 ≤ N ≤ 105), o número de pontos dados.
A segunda linha contém N inteiros Xi (1 ≤ Xi ≤ 103) para 1 ≤ i ≤ N, representando os comprimentos dos arcos entre dois pontos consecutivos na circunferˆencia: para 1 ≤ i ≤ (N − 1), Xi representa o comprimento do arco entre os pontos i e i + 1; XN representa o comprimento do arco entre os pontos N e 1. O final da entrada é determinado por EOF (fim de arquivo).

Saída
Seu programa deve produzir uma única linha para cada caso de teste, contendo um único inteiro, o número de triângulos equiláteros distintos que podem ser construídos utilizando os pontos dados como vértices.

*/

int main()
{
  int N, n[100000], i, j, cont, aju, total, Total, loop;
  while(scanf("%d", &N) != EOF)
  {
    i = 0;
    scanf("%d", &n[i]);
    cont = n[i];
    for(i = 1; i < N; i++)
    {
      scanf("%d", &n[i]);
      cont = cont + n[i];
      n[i] += n[i - 1];
    }
    cont = cont / 3;
    for(i = 0; i < N; i++)
    {
      if(std::binary_search (n, n + N, n[i] + cont)  && std::binary_search (n, n + N, n[i] + (cont * 2)))
        Total++;
    }

    printf("%d\n", Total);
    Total = 0;
  }
  return 0;
}