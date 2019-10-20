#include <stdio.h>

int main(){
	int A[100][100];
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%d", A[j][i]);
			if(j != N - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
} 
