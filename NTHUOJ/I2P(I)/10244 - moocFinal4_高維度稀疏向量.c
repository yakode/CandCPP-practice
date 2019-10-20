#include <stdio.h>
#include <stdlib.h>

int data[1000000][2];

int main(){
	int a, b;
	int N = 0;
	while(1){
		scanf("%d:%d", &a, &b);
		if(a == 0 && b == 0) break;
		data[N][0] = a;
		data[N][1] = b;
		N++;
	}
	long long int ans = 0;
	while(1){
		scanf("%d:%d", &a, &b);
		if(a == 0 && b == 0) break;
		if(b == 0) continue;
		for(int i = 0; i < N; i++){
			if(data[i][0] == a){
				ans += b * data[i][1];
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
