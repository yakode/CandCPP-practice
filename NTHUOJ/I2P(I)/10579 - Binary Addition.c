#include <stdio.h>

int main(){
	int T, N;
	char num1[100000], num2[100000];
	int ans[100000];
	int carry = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		scanf("%s", num1);
		scanf("%s", num2);
		for(int i = N - 1; i >= 0; i--){
			//ASCII 0:48
			ans[i] = num1[i] + num2[i] + carry - 48 * 2;
			if(ans[i] > 1){
				carry = 1;
				ans[i] -= 2;
			} else carry = 0;
		}
		//if(carry) printf("1");
		for(int i = 0; i < N; i++) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
} 
