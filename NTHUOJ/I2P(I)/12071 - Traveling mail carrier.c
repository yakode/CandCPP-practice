#include <stdio.h>

int seen[11];
int map[11][11]; //map[x][y] = distance from x to y
int distance, distance_min = 2147483640;
int N; //there are N places

void deliver(int n, int from){
	if(n == N){
		distance += map[from][0];
		if(distance < distance_min)
			distance_min = distance;
		distance -= map[from][0];
	}

	for(int i = 1; i < N; i++){
		if(seen[i] == 0){
			seen[i] = 1;
			distance += map[from][i];
			deliver(n+1, i);
			seen[i] = 0;
			distance -= map[from][i];
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	
	distance = 0;	
	seen[0] = 1;
	deliver(1, 0);

	printf("%d\n", distance_min);

	return 0;
}
