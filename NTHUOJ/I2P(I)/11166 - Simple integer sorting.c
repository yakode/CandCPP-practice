#include <stdio.h>

int main(){
	int T, N, V[10000+10];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int n = 0; n < N; n++)
			scanf("%d", &V[n]);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N - i - 1; j++){
				if(V[j] > V[j+1]){
					V[j] += V[j+1];
					V[j+1] = V[j] - V[j+1];
					V[j] -= V[j+1];
				}
			}
		printf("%d", V[0]);
		for(int n = 1; n < N; n++)
			printf(" %d", V[n]);
		printf("\n");
	}
	return 0;
}
