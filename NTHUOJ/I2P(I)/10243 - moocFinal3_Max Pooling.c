#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	int data[10][10];
	int ans[10][10];
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &data[i][j]);
	for(int i = 0; i < N - 2; i++)
		for(int j = 0; j < N -2; j++){
			int max = data[i][j];
			for(int p = 0; p <3; p++)
				for(int q = 0; q < 3; q++)
					if(data[i+p][j+q] > max) max = data[i+p][j+q];
			if(j == N-2-1) printf("%d\n", max);
			else printf("%d ", max);	
		}
	return 0;
}
