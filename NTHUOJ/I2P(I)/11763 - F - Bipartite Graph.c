#include <stdio.h>
#include <stdlib.h>
int bond[2000][2000];
int color[2000];
int flag;
void initial(int n){
	flag = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			bond[i][j] = 0;
		color[i] = -1;
	}
}

void paint(int which, int i, int n){
	if(flag == 1) return;
	
	if(color[i] != -1 && color[i] != which % 2)
		flag = 1;
	else if(color[i] == -1){
		color[i] = which % 2;
		for(int k = 1; k <= n; k++)
			if(bond[i][k] == 1)
				paint(which+1, k, n);
	}
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int node, edge;
		scanf("%d%d", &node, &edge);
		initial(node);
		while(edge--){
			int a, b;
			scanf("%d%d", &a, &b);
			bond[a][b] = 1;
			bond[b][a] = 1;
		}

		paint(0, 1, node);

		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
}

