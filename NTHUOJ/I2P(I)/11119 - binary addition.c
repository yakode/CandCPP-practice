#include<stdio.h>

int main(){
	int N;
	int binary[20] = {};
	scanf("%d",&N);
	int i;
	int jud = 1, ans = 0;
	for (i = 0; N != 0; i++){
		binary[i] = N % 2;
		N /= 2;
		if(binary[i] == 0 && jud == 1){
			jud = 0;
			if(i == 0) binary[0] = 1;
			else if(i != 0){
				for(int j = 0; j < i; j++) binary[j] = 0;
				binary[i] = 1;
				ans = i;
			}
		}
	}
	if(jud == 1){
		binary[i] = 1;
		i++;
		for(int j = 0; j < i-1; j++) binary[j] = 0;
		ans = i-1;
	}
	int start = 0;
	i--; 
	for( ; i>=0; i--){
		if(binary[i] == 1) start = 1;
		if(start) printf("%d",binary[i]);
	}
	printf(" %d",ans);
	return 0;
} 
