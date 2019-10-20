#include <stdio.h>
#include <math.h>
long long int A[10][10];
int col[10] = {};
int N;

long long int determinant(int n){
	if(n == 0) return 1;
	long long int ans = 0;
	int flag = 1;
	for(int i = 0; i < N; i++){
		if(col[i] == 0){
			col[i] = 1;
			ans += flag * A[N - n][i] * determinant(n - 1);
			col[i] = 0;
			flag *= -1;
		}
	}
	return ans;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%lld", &A[i][j]);
	printf("%lld\n", determinant(N));
	return 0;
}
