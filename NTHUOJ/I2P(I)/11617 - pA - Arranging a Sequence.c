#include <stdio.h>
int head[1000000], visited[1000000];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = m - 1; i >= 0; i--){
		scanf("%d", &head[i]);
	}
	for(int i = 0; i < m; i++){
		if(visited[head[i]] == 0){
			printf("%d\n", head[i]);
			visited[head[i]] = 1;
		}
		
	}
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0) printf("%d\n", i);
	}
	return 0;
} 
