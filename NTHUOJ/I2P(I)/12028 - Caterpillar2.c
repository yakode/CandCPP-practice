#include <stdio.h>

int main(){
	int L, Li[100000];
	scanf("%d", &L);
	for(int i = 0; i < L; i++){
		scanf("%d", &Li[i]);
	}
	printf("..ùã¡ó ¡óùå..\n");
	for(int i = 0; i < L; i++){
		for(int j = 0; j < Li[i]; j++) printf(".");
		printf("ùãùù(¢i¢i¢i)ùùùå\n");
	}
	return 0;
}
