#include <stdio.h>
long long int s[10000+5];

long long int gcd(long long int a, long long int b)
{
	while(a != 0 && b != 0){
		a = a % b;
		a += b;
		b = a - b;
		a -= b;
	}
	return a + b;
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; i++)
			scanf("%lld", &s[i]);
		for(int i = 0; i < (N - 1); i++)
			s[i + 1] = gcd(s[i], s[i + 1]);
		printf("%lld\n", s[N-1]);
	}
	return 0;
}
