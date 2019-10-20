#include <stdio.h>

int main(){
	int N, L;
	char C;
	scanf("%c%d%d", &C, &L, &N);
	for(int n = 0; n < N; n++){
		if(L == 1){
			printf("%c", C);
			if(n != N-1) printf("\n");
			continue;
		}
		for(int l = 1; l <= L; l++){
			int tmp = l;
			while(tmp--) printf("%c", C);
			printf("\n");
		}
		for(int l = 1; l < L-1; l++){
			int tmp = L - l;
			while(tmp--) printf("%c", C);
			printf("\n");
		}
	}
	if(L > 1 && N > 0)printf("%c", C);
	return 0;
}
