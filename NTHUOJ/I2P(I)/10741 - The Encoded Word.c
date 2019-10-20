#include <stdio.h>
#include <stdlib.h>

int main(){
	int num[3];
	scanf("%d",&num[1]);
	num[0] = num[1] / 100;
	num[2] = num[1] % 10;
	num[1] = (num[1] - (num[0]*100+num[2])) / 10;
	char word[3];
	for(int i = 0; i < 3; i++){
		word[i] = 'A' * ((num[i] + 1) % 2) + 'B' * (num[i] % 2) + i * 2;
		printf("%c",word[i]);
	}
	return 0;
}
