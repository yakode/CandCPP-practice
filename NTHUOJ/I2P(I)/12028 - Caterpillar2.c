#include <stdio.h>

int main(){
	int L, Li[100000];
	scanf("%d", &L);
	for(int i = 0; i < L; i++){
		scanf("%d", &Li[i]);
	}
	printf("..��� ����..\n");
	for(int i = 0; i < L; i++){
		for(int j = 0; j < Li[i]; j++) printf(".");
		printf("����(�i�i�i)����\n");
	}
	return 0;
}
