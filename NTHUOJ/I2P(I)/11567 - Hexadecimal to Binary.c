#include <stdio.h>

int main(){
	int X, Y;
	scanf("%x%x", &X, &Y);
	int plus = X +Y;
	int bi[1000] = {};
	int i = 0;
	while(plus > 0){
		bi[i] = plus % 2;
		plus /= 2;
		i++;
	}
	i--;
	while(i >= 0){
		printf("%d",bi[i]);
		i--;
	}
	return 0;
}
