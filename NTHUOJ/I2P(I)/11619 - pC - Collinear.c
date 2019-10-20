#include <stdio.h>
#include <stdlib.h>

long long int gcd(long long int a, long long int b){
	while(a != 0 && b != 0){
		if(a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main(){
	int T, N;
	long long  x[1000], y[1000];
	scanf("%d", &T);
	while(T--){
		int count = 0;
		long long int line[100000][3] = { }, line_num = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%lld%lld", &x[i], &y[i]);
		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				long long int a = y[j] - y[i];
				long long int b = x[i] - x[j];
				if(a != 0 && b != 0){
					long long int factor = gcd(abs(a), abs(b));
					a /= factor;
					b /= factor;
				}
				else if(a != 0 && b == 0) a = 1;
				else if(b != 0 && a == 0) b = 1;
				if(a < 0){
					a *= -1;
					b *= -1;
				}
				long long int c = x[i] * a + y[i] * b;
				int non_used = 1;
				for(int k = 0; k < line_num; k++){
					if(a == line[k][0] && b == line[k][1] && c == line[k][2]){
						non_used = 0;
						break;
					}
				}
				if(non_used){
					line[line_num][0] = a;
					line[line_num][1] = b;
					line[line_num][2] = c;
					line_num ++;
					for(int k = 0; k < N; k++){
						if(k != i && k != j){
							if(a * x[k] + b * y[k] == c){
								count ++;
								break;
							}
						}
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
