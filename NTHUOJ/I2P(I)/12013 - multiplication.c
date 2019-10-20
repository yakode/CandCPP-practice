#include<stdio.h>

int main(){
	unsigned long long K, M, N;
	scanf("%llu%llu%llu",&K ,&M ,&N);
	unsigned long long ans = M * N;
	printf("%0*llu\n",K,ans);
	return 0;
} 
