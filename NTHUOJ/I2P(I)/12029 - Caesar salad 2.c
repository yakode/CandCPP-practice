#include <stdio.h>

int main(){
	long long N;
	char letter[5];
	for(int i = 0; i < 3; i++) scanf("%c", &letter[i]);
	scanf("%lld", &N);
	N = -N;
	N %= 26;
	for(int i = 0; i < 3; i++){
		letter[i] += N;
		if(letter[i] > 65+25) letter[i] -= 26;
		printf("%c", letter[i]);
	}
	printf("\n");
	return 0;
}
