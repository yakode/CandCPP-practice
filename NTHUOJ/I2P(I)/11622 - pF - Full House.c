#include <stdio.h>
#include <stdlib.h>

int exchange(char c){
	if(c == 'A') return 1;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	if(c == '1') return 10;
	else return c - '0';
}

int main(){
	int T;
	char x[10];
	scanf("%d", &T);
	while(T--){
		int kind[2][2]; // 0 what 1 num
		int n = 0;
		for(int i = 0; i < 5; i++){
			scanf("%s", x);
			if(n < 3){
				int pi = exchange(x[0]);
				if(n == 0){
					kind[0][0] = pi;
					kind[0][1] = 1;
					n++; 
				}
				else if(n == 1){
					if(pi == kind[0][0]) kind[0][1] ++;
					else{
						n++;
						kind[1][0] = pi;
						kind[1][1] = 1;
					}
				}
				else if(n == 2){
					if(pi == kind[0][0]) kind[0][1] ++;
					else if(pi == kind[1][0]) kind[1][1] ++;
					else n++;
				}
			}
		}
		if(n != 2) printf("NO\n");
		else if(abs(kind[0][1] - kind[1][1]) == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
