#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M;
	int area[100][100];
	int min = -1;
	int ip_x, ip_y;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &area[i][j]);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int dis = 0;
			for(int m = 0; m < N; m++){
				for(int n = 0; n < M; n++){
					dis += area[m][n] * (abs(i - m) + abs(j - n));
				}
			}
			if(dis < min){
				min = dis;
				ip_x = i;
				ip_y = j;
			}
			else if(min == -1){
				min = dis;
				ip_x = i;
				ip_y = j;
			}
		}
	}
	printf("%d %d\n", ip_x, ip_y);
}
