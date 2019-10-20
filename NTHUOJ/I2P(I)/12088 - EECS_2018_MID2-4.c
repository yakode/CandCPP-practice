#include <stdio.h>
int max = -1;
int col[8];
int map[8][8];


int valid(int _row, int _col){
	for(int i = 0; i < _row; i++){
		if(_col == col[i]) return 0;
		if(_col - col[i] == _row - i) return 0;
		if(_col - col[i] == i - _row) return 0;
	}
	return 1;
}

void Q(int n){
	if(n == 8){
		int score = 0;
		for(int i = 0; i < 8; i++)
			score += map[i][ col[i] ];
		if(score > max) max = score;
	}

	for(int i = 0; i < 8; i++){
		if(valid(n, i)){
			col[n] = i;
			Q(n + 1);
		}
	}
}

int main(){
	int K;
	scanf("%d", &K);
	while(K--){
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				scanf("%d", &map[i][j]);
		
		max = -1;
		Q(0);
		printf("%d\n", max);
	}
	return 0;
}
