#include <stdio.h>

int main(){
	int a[200000+1]; // index of watermelons from top to bottom
	int b[200000+1]; // order of watermelons  that Osas' wants to eat
	int c[200000+1] = {0}; // if watermelon with index i has been eatean
	int n;

	// input
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);

	// compute and output
	int j = 0; // index for a
	for(int i = 0; i < n; ++i){
		if(c[b[i]] == 1){
			// if watermelon i has been eaten
			printf("0");
		}else{
			int count = 0; // count Osas need to eat how many watermelons
			while(1){
				c[a[j]] = 1;
				j++;
				count++;
				if(a[j-1] == b[i]) break;
			}
			printf("%d", count);
		}
		if(i == n-1) printf("\n");
		else printf(" ");
	}
	return 0;
}
