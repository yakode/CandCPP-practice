#include <stdio.h>
int map[1000][1000];

int main(){
	int N, M, X;
	int done = 0;
	scanf("%d%d%d", &N, &M, &X);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	for(int i = 0; i < N - X + 1; i++){
		if(done == 1) break;
		for(int j = 0; j < N - X + 1; j++){
			if(done == 1) break;
			if(map[i][j] == 0){
				int tmp = 1;
				for(int k = i; k < i + X; k++){
					if(tmp == 0) break;
					for(int l = j; l < j + X; l++){
						if(map[k][l] == 1){
							tmp = 0;
							break;
						}
					}
				}
				if(tmp == 1) done = 1;
			}
		}
	}
	if(done == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
