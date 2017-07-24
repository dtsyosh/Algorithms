#include <stdio.h>
#define tamanho 50

void exibirMatriz(int matriz[][tamanho], int vertices);
void dijkstra(int matriz[][tamanho], int distancia[], int quantidadeVertices, int verticeInicial,int verticeFinal);

void main()
{
	int matrizAdj[tamanho][tamanho];	// Matriz de adjacencia
	int quantidadeVertices;				// Quantidade de vertices ( usado como tamanho para a matriz)
	int quantidadeArestas;				// Quantidade de arestas
	int peso;							// Peso da aresta em questão
	int verticeInicial, verticeFinal;	// Vertices escolhidos pelo usuário para o trajeto
	int distancia[tamanho];				// Vetor que guardará a distancia do ponto inicial até todos os vertices

	int linha, coluna, i;

	//printf("Quantidade de vertices: ");
	scanf("%d", &quantidadeVertices);
	//printf("Quantidade de arestas: ");
	scanf("%d", &quantidadeArestas);

	for(linha = 1; linha <= quantidadeVertices; linha++)				//Inicializa a matriz adjacente
		for(coluna = 1; coluna <= quantidadeVertices; coluna++)
			matrizAdj[linha][coluna] = 0;

	for(i = 1; i <= quantidadeArestas; i++)
	{
		//printf("Digite a ligacao e seu peso (Obs: Vertice1 -> Vertice2): ");
		scanf("%d %d %d", &linha, &coluna, &peso);
		matrizAdj[linha][coluna] += peso;
		matrizAdj[coluna][linha] += peso;
	}

	//printf("Qual caminho deseja fazer? (Vertice inicial/Vertice final) :");
	scanf("%d %d", &verticeInicial, &verticeFinal);
	
	dijkstra(matrizAdj, distancia, quantidadeVertices, verticeInicial, verticeFinal);

	//exibirMatriz(matrizAdj, quantidadeVertices);




}

void dijkstra(int matriz[][tamanho], int distancia[], int quantidadeVertices, int verticeInicial,int verticeFinal)
{
	int fechaVertice[tamanho];			//Vertices que ja foram fechados
	int contador, menorDistancia, vertMenorDistancia, i, linha, coluna;
	int verticeAtual; 	
    int caminho[50];


	for(linha = 1; linha <= quantidadeVertices; linha++)		
		for(coluna = 1; coluna <= quantidadeVertices; coluna++)
			if(matriz[linha][coluna] == 0)
				matriz[linha][coluna] = 999;


	for(contador = 1; contador <= quantidadeVertices; contador++)
	{
		fechaVertice[contador] = 0;		//Estado do vertice
		distancia[contador] = matriz[verticeInicial][contador];		//Adquirindo a distancia dos vizinhos da origem
	}

	fechaVertice[verticeInicial] = 1;
	contador = 2;		//Começa em 2 pois o ponto de origem não entra nos calculos

	while(contador <= quantidadeVertices)
	{
		menorDistancia = 99;

		for(i = 1; i <= quantidadeVertices; i++)
		{
			if(distancia[i] < menorDistancia && !fechaVertice[i])			// Se a distância do vertice 'i' for menor do que o da variavel Dist e o vertice não estiver fechado
			{
				menorDistancia = distancia[i];		// Grava uma distancia menor
				vertMenorDistancia = i;				//Gravo o vertice que pertencie a menor distancia gravada
			}
		}

		fechaVertice[vertMenorDistancia] = 1;     //Fecho o vertice com a menor distancia.

		for(i = 1; i <= quantidadeVertices; i++)			//Atualiza as distancias passando por este vertice
		{
			if( (distancia[vertMenorDistancia] + matriz[vertMenorDistancia][i]) < distancia[i] && !fechaVertice[i])	//Se a soma do custo do vertice atual + o caminho pro proximo vertice for menor que o custo do proximo vertice E ele estiver aberto
				distancia[i] = distancia[vertMenorDistancia] + matriz[vertMenorDistancia][i];						//Atualizo o custo daquele vertice passando pelo vertice atual
		}

		contador++;

	}

// Código para calcular a rota tomada para a escolha do usuário
 
    distancia[verticeInicial] = 0;               
 	caminho[0] = verticeFinal;
 	verticeAtual = verticeFinal;
 	contador = 1;
 	while(verticeAtual != verticeInicial)
 	{
 		for(i = 1; i <= quantidadeVertices; i++)
 		{
 			if(distancia[verticeAtual] - matriz[verticeAtual][i] == distancia[i])
 			{				
 				caminho[contador] = i;
 				contador++;
 				verticeAtual = i;

 				break;
 			}

 		}
 	}
 

	printf("Caminho minimo : ");
    for (i = contador-1; i > 0; i--)
       printf("%d -> ",caminho[i]);         
    printf(" %d", caminho[0]);


}


void exibirMatriz(int matriz[][tamanho], int vertices)
{
	int linha, coluna;

	for(linha = 1; linha <= vertices; linha++)
	{
		for(coluna = 1; coluna <= vertices; coluna++)
			printf("%3d", matriz[linha][coluna]);
		printf("\n");
	}
}

