#include <stdio.h>
#include <string.h>

int main(){
	char A[100], B[100];
	int n;
	int max = 0;
	scanf("%s%d", A, &n);
	int len_A = strlen(A);
	while(n--){
		scanf("%s", B);
		int count = 0;
		int len_B = strlen(B);
		for(int i = 0; i < len_B - len_A + 1; i++){
			if(B[i] == A[0]){
				int jud = 1;
				for(int j = i + 1, k = 1; k < len_A; j++, k++){
					if(B[j] != A[k]){
						jud = 0;
						break;
					}
				}
				if(jud) count++;
			}
		}
		if(count > max) max = count;
	}
	printf("%d", max);
	return 0;
} 
