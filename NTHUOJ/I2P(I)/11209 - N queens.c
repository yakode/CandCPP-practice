#include <stdio.h>
int N, col[10], count = 0;
int valid(int _row, int _col){
	for(int i = 0; i < _row; i++){
		if(col[i] == _col) return 0;
		if(col[i] - _col == i - _row) return 0;
		if(col[i] - _col == _row - i) return 0;
	}
	return 1;
}
void Q(int n){
	if(n == N){
		count ++;
		return ;
	}
	for(int i = 0; i < N; i++){
		if(valid(n, i)){
			col[n] = i;
			Q(n+1);
		}
	}
}

int main(){
	scanf("%d", &N);
	Q(0);
	printf("%d\n", count);
	return 0;
} 
