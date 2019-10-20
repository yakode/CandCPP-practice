#include <stdio.h>

int main(){
	int stomach, leg, tail;
	scanf("%d%d%d",&stomach ,&leg ,&tail);
	int cow, chicken, alpaca;
	cow = tail - (leg - stomach);
	alpaca = ((leg - cow*4) - 2*(tail - cow))/2;
	chicken = tail - cow - alpaca;
	printf("%d %d %d\n",chicken ,cow ,alpaca);
	return 0;
} 
