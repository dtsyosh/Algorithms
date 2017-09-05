#include <stdio.h>

int tamanho(char C[])
{
	int i = 0;
	while(C[i] != '\0')
	{
		i++;
	}
	return i;
}

int main()
{
	int N[3], i = 1, Resposta;
	char Valor[5001];
	scanf(" %s", Valor);
	N[0] = 1;
	N[1] = 1;
	while(Valor[i] != '\0')
	{
		//printf("i = %d, i - 1 = %d, resposta = %d", Valor[i] - 48, Valor[i - 1] - 48, (Valor[i] - 48) + ((Valor[i - 1] - 48)* 10));
		Resposta = (Valor[i] - 48) + ((Valor[i - 1] - 48)* 10);
		if(
			(
				(
					(Valor[i - 1] - 48 > 0 && Valor[i] - 48 == 0) || (Valor[i] - 48 > 0 && Valor[i - 1] - 48 == 0)
				) 
				&& 
				(Resposta < 27)
			)
			|| 
			(
				(Resposta < 27 && Resposta != 0 && Valor[i - 1] - 48 != 0) 
				&& 
				Valor[i + 1] - 48 == 0 
				&& 
				tamanho(Valor) != i
			)
		  )
		{
			//printf("	entrou 0\n");
			N[2] = N[1];
		}
		else
		{
			if(
				Resposta < 27 
				&& 
				Resposta != 0 
				&& 
				Valor[i - 1] - 48 != 0
			  )
			{
				N[2] = N[0] + N[1];
				//printf("	entrou 1\n");
			}
			else
			{
				if(
					(
						Resposta > 26 
						&& 
						Valor[i] - 48 != 0
					)
				  )
				{
					N[2] = N[1];
					//printf("	entrou 2\n");
				}
				else
				{
					//printf("	entrou 3\n");
					N[2] = 0;
					N[1] = 0;
					N[0] = 0;
					break;
				}
			}
		}
		i++;
		N[0] = N[1];
		N[1] = N[2];
	}
	printf("%d\n", N[1]);
	return 0;
}
