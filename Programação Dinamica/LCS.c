#include <stdio.h>
#define MAX 50

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
	char A[MAX], B[MAX];
	int TA, TB, i, j;
	scanf(" %s", A);
	scanf(" %s", B);
	TA = tamanho(A);
	TB = tamanho(B);
	printf("%d %d\n", TA, TB);
	int Matriz[TA + 1][TB + 1];

	for(i = 0; i <= TA; i++)
		Matriz[0][i] = 0;

	for(i = 0; i <= TB; i++)
		Matriz[i][0] = 0;

	for(i = 1; i <= TA; i++){
		for(j = 1; j <= TB; j++){
			if(A[i - 1] == B[j - 1]){
				Matriz[i][j] = Matriz[i - 1][j - 1] + 1;
			}
			else{
				if(Matriz[i - 1][j] > Matriz[i][j - 1]){
					Matriz[i][j] = Matriz[i - 1][j];
				}
				else{
					Matriz[i][j] = Matriz[i][j - 1];
				}
			}
		}
	}

	printf("%d\n", Matriz[TA][TB]);

	return 0;

}