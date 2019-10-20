#include <stdio.h>
int total[2000+5][2000+5];

int main(){
	int N, M, Q, x1, x2, y1, y2;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			int tmp;
			scanf("%d", &tmp);
			total[i][j] = total[i - 1][j] + total[i][j - 1] - total[i - 1][j - 1] + tmp;
		}
	}
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int sum = total[x2][y2] - total[x1 - 1][y2] - total[x2][y1 - 1] + total[x1 - 1][y1 - 1];
		printf("%d\n", sum);
	}
	return 0;
} 
