#include <stdio.h>

int main(){
	int T, L, R;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d", &L, &R);
		int max = -1, ip = L;
		for(int i = L; i <= R; i++){
			int tmp = 0;
			int j = 1;
			for(; j*j < i; j++){
				if (i % j == 0) tmp++;
			}
			if(j*j == i) tmp = tmp * 2 + 1;
			else tmp *= 2;
			if(tmp > max){
				max = tmp;
				ip = i;
			}
		}
		printf("%d\n",ip);
	}
	return 0;
}
