#include <stdio.h>
#include <math.h>

int MOD(long long int a, long long int n, long long int p){
	if(n == 0) return 1;
	long long int mod = MOD(a, n/2, p);
	if(n % 2 == 0) return (mod * mod) % p;
	else return  (((mod * mod) % p) * (a % p)) % p;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		long long int a, n, p;
		scanf("%lld%lld%lld", &a, &n, &p);
		long long int ans = MOD(a, n, p);
		printf("%lld\n", ans);
	}
	return 0;
} 
