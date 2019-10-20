#include <stdio.h>

int main(){
	int X, tri[1000];
	scanf("%d", &X);
	int i = 0;
	while(X > 0){
		tri[i] = X % 3;
		X /= 3;
		i++;
	}
	for(i--; i>=0; i--) printf("%d", tri[i]);
	printf("\n");
	return 0;
}
