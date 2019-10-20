#include <stdio.h>

unsigned long long int gcd(unsigned long long int x, unsigned long long int y){
	unsigned long long int a = x, b = y;
	while(a != 0 && b != 0){
		if(a > b) a %= b;
		else b %= a;
	}
	unsigned long long int gcd = a + b;
	return gcd;
}

unsigned long long int lcm(unsigned long long int x, unsigned long long int y){
	unsigned long long int a = x, b = y;
	while(a != 0 && b != 0){
		if(a > b) a %= b;
		else b %= a;
	}
	unsigned long long int gcd = a + b;
	return (x / gcd) * y;
}

int main(){
	int T;
	unsigned long long int N, x;
	scanf("%d", &T);
	while(T--){
		scanf("%llu", &N);
		unsigned long long int factor = 1;
		for(int i = 0; i < 3; i++){
			scanf("%llu", &x);
			x = gcd(N, x);
			factor = lcm(factor, x);
		} 
		unsigned long long int ans = N / factor;
		printf("%llu\n", ans);
	}
	return 0;
} 
