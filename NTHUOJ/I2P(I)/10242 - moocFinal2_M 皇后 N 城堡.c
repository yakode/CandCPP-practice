#include <stdio.h>
#include <stdlib.h>

int N, M, count;
int col[100][2]; // [0] -> 2queen 1rook, [1] -> which col

int check_rook(int _row, int _col){
	
	for(int i = 0; i < _row; i++){
		if(col[i][0] == 1){
			//rook
			if(col[i][1] == _col) return 0;
		}
		else if(col[i][0] == 2){
			//queen
			if(col[i][1] == _col) return 0;
			if(col[i][1] - _col == i - _row) return 0;
			if(col[i][1] - _col == _row - i) return 0;
		}
	}

	return 1;
}

int check_queen(int _row, int _col){
	for(int i = 0; i < _row; i++){
		if(col[i][1] == _col) return 0;
		if(col[i][1] - _col == i - _row) return 0;
		if(col[i][1] - _col == _row - i) return 0;
	}

	return 1;
} 

void show(){
	/*for(int i = 0; i < (N+M); i++){
		for(int j = 0; j < (N+M); j++){
			if(j == col[i][1]) printf("%d", col[i][1]);
			else printf("0");
		}
		printf("\n");
	}*/
	for(int i = 0; i < (N+M); i++)
		printf("%d", col[i][1]);
	printf("\n");
}

void put(int row, int n, int m){
	if(row > (N+M)) return;
	if(n == N && m == M){
		count ++;
		return;
	}
	if(n < N){
		for(int i = 0; i < (N+M); i++){
			if(check_rook(row, i)){
				col[row][0] = 1;
				col[row][1] = i;
				put(row+1, n+1, m);
			}
		}
	}
	if(m < M){
		for(int i = 0; i < (N+M); i++){
			if(check_queen(row, i)){
				col[row][0] = 2;
				col[row][1] = i;
				put(row+1, n, m+1);
			}
		}
	}
}

int main(){
	count = 0;
	scanf("%d%d", &M, &N);
	put(0, 0, 0);
	printf("%d\n", count);
	return 0;
}
