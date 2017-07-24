#include <stdio.h>
#include <malloc.h>
#define tamanho 50

typedef struct bloco{
	int vertice1;
	int vertice2;
	int custo;
	int resposta;
	struct bloco* proximo;
}bloco;


void insereOrdenado(bloco* arestas, int vertice1, int vertice2, int custo);
void achaCicloDFS(int vertice, int parent);
void exibeLista(bloco* arestas);
void liberaMemoria(bloco* arestas);
void kruskal(bloco* arestas);
void exibeMatriz();

	int matrizAdj[tamanho][tamanho];	// Matriz de adjacencia
	int visitado[tamanho];
	int quantidadeVertices;				// Quantidade de vertices ( usado como tamanho para a matriz)
	int quantidadeArestas;				// Quantidade de arestas
	int custo;							// Peso da aresta em questão
	int temCiclo;

void main()
{
	
	bloco* arestas = (bloco*)malloc(sizeof(bloco));
	arestas->proximo = NULL;
	int linha, coluna, i, vertice1, vertice2;
	for(i = 1; i < tamanho; i++) visitado[i] = 0;
	//printf("Quantidade de vertices: ");
	scanf("%d", &quantidadeVertices);
	//printf("Quantidade de arestas: ");
	scanf("%d", &quantidadeArestas);
	for(linha = 1; linha <= quantidadeVertices; linha++)				//Inicializa a matriz adjacente
		for(coluna = 1; coluna <= quantidadeVertices; coluna++)
			matrizAdj[linha][coluna] = 0;

	for(i = 1; i <= quantidadeArestas; i++)
	{
		//printf("Digite a ligacao e seu custo (Obs: Vertice1  Vertice2  Custo): ");
		scanf("%d %d %d", &vertice1, &vertice2, &custo);
		insereOrdenado(arestas, vertice1, vertice2, custo);
	}
	kruskal(arestas);
	system("cls");
	printf("Arestas pertencentes ao conjunto-resposta.\n");
	exibeLista(arestas);
	liberaMemoria(arestas);
}

void kruskal(bloco* arestas)	//DONE
{
	int quantidadeArestasAdicionadas = 1, i;
	bloco* arestaAtual = arestas->proximo;
	bloco* arestaAnterior;

	while(quantidadeArestasAdicionadas < quantidadeVertices)
	{
		matrizAdj[arestaAtual->vertice1][arestaAtual->vertice2] = arestaAtual->custo;
		matrizAdj[arestaAtual->vertice2][arestaAtual->vertice1] = arestaAtual->custo;
		temCiclo = 0;
		achaCicloDFS(arestaAtual->vertice1, 9999);
		if(temCiclo){
			matrizAdj[arestaAtual->vertice1][arestaAtual->vertice2] = 0;	//Se tiver ciclo, cancela a adição da aresta e avança pra proxima
			matrizAdj[arestaAtual->vertice2][arestaAtual->vertice1] = 0;
			arestaAtual = arestaAtual->proximo;
		}
		else
		{
			arestaAtual->resposta = 1;
			quantidadeArestasAdicionadas++;
			arestaAtual = arestaAtual->proximo;
		}
		for(i = 1; i <= quantidadeVertices; i++) visitado[i] = 0;

	}
}

void achaCicloDFS(int vertice, int parent)	//DONE
{
    int i, vizinhos[quantidadeVertices], quantidadeVizinhos = 0, j;

    visitado[vertice] = 1;  //marca como visitado

    for (i = 1; i <= quantidadeVertices; ++i)
    	if(matrizAdj[vertice][i] != 0 && i != parent)
    		vizinhos[++quantidadeVizinhos] = i;

    for(i = 1; i <= quantidadeVizinhos; i++)
    {
    	if(visitado[vizinhos[i]] != 1)
    		achaCicloDFS(vizinhos[i], vertice);
    	else
    	{
    		temCiclo = 1;
    		return;
    	}

    }
}

void insereOrdenado(bloco* arestas, int vertice1, int vertice2, int custo)	//DONE
{
	bloco* novo = (bloco*)malloc(sizeof(bloco));
	novo->vertice1 = vertice1;
	novo->vertice2 = vertice2;
	novo->custo = custo;
	novo->resposta = 0;
	novo->proximo = NULL;

	
	if(arestas->proximo == NULL)
		arestas->proximo = novo;
	else
	{
		bloco* tmp = arestas->proximo;
		bloco* anterior = NULL;

		while(tmp != NULL && tmp->custo < custo)
		{
			anterior = tmp;
			tmp = tmp->proximo;
		}

		if(!anterior){
			novo->proximo = arestas->proximo;
			arestas->proximo = novo;
		}else
		{
			anterior->proximo = novo;
			novo->proximo = tmp;
		}
	}

	return;
}

void exibeLista(bloco* arestas)	//DONE
{
	bloco* tmp = arestas->proximo;

	while(tmp != NULL)
	{
		if(tmp->resposta == 1)
			printf("%d <-> %d = %d\n", tmp->vertice1, tmp->vertice2, tmp->custo);
		tmp = tmp->proximo;
	}
}

void liberaMemoria(bloco* arestas)	//DONE
{
	if(arestas->proximo)
	{
		bloco* proximo;
		bloco* atual = arestas->proximo;

		while(atual != NULL)
		{
			proximo = atual->proximo;
			free(atual);
			atual = proximo;
		}
	}
}

void exibeMatriz()	//DONE
{
	int linha, coluna;

	for(linha = 1; linha <= quantidadeVertices; linha++)
	{				
		for(coluna = 1; coluna <= quantidadeVertices; coluna++)
			printf("%2d ", matrizAdj[linha][coluna]);
		printf("\n");
	}
	puts("");
}