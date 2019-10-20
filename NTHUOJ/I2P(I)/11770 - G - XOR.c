#include <stdio.h>

int main(){
	int n;
	int max = 0;
	unsigned long long int a;
	unsigned long long int ones[1000] = {};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%llu", &a);
		int j = 0;
		for(int j = 0; a != 0; j++){
			if(a % 2 == 1) 
				ones[j]++;
			a /= 2;
			if(j > max)
				max = j;
		}
	}
	
	unsigned int base2 = 1;
	unsigned long long int sum = 0;
	for(int i = 0; i <= max; i++){
		if( ones[i] > (n/2) )
			sum += base2 * (n - ones[i]);
		else
			sum += base2 * ones[i];
		base2 *= 2;
	}

	printf("%llu\n", sum);
	return 0;
}
