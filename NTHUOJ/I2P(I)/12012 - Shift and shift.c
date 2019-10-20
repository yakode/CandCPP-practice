#include <stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	int b = a/100 + a%100*100;
	int c = a * b;
	printf("%d\n",c);
	return 0;
}
