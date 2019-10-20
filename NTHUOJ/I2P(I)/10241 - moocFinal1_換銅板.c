#include <stdio.h>

int N, n, cur[100], count[100];
int goal;

void change(int now, int n){
	if(n >= N) return;
	if(now == 0){
		printf("(");
		for(int i = 0; i < N-1; i++)
			printf("%d,", count[i]);
		printf("%d)\n", count[N-1]);
		return;
	}
	change(now, n+1);
	if(now - cur[n] >= 0){
		count[n]++;
		change(now-cur[n], n);
		count[n]--;
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &cur[i]);
	scanf("%d", &goal);
	change(goal, 0);
	return 0;
}
