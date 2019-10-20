#include <stdio.h>
int map[2500][2500];
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
int dir, x, y;
int main(){
	int T, N;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		x = 0;
		y = -1;
		for(int i = 0; i < N; i++){
			dir = i % 4;
			int j = 0;
			for(; j < N - i; j++){
				x += dir_x[dir];
				y += dir_y[dir];
				map[x][y] = T + 1;
			}
		}
		for(int i = 0; i < N; i++){
			for(int k = 0; k < N; k++){
				if(map[i][k] == T + 1) printf("#");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
} 
