#include <stdio.h>
long long int total[1000000+5];

int main(){
	int N, M;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		long long int tmp;
		scanf("%lld", &tmp);
		total[i] = total[i-1] + tmp;
	}
	
	int L, R;
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		scanf("%d%d", &L, &R);
		long long int sum = total[R] - total[L - 1];
		printf("%lld\n", sum);
	}
	return 0;
} 
