#include <stdio.h>

int m, n;
int map[1000+5][1000+5] = {};

void water(int x, int y){
	if(map[x][y] == 0) return;
	map[x][y] = 0;
	water(x+1, y);
	water(x-1, y);
	water(x, y+1);
	water(x, y-1);
}

int main(){
	int pond = 0;
	char s[1000];
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++){
		scanf("%s", s);
		for(int j = 1; j <= n; j++){
			if(s[j-1] == '~')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(map[i][j] == 1){
				pond ++;
				water(i, j);
			}
		}
	}
	printf("%d\n", pond);
	return 0;
}

