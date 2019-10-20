#include <stdio.h>
#include <string.h>

int m, n;
char map[1000][1000];
int DONE = 0;
int max[100];

void run(int x, int y)
{
	if(DONE) return;
	if(x < 0 || y < 0 || x >= m || y >= n) return;
	if(map[x][y] == '^') return;
	if(map[x][y] == '~'){
		DONE = 1;
		return;
	}
	else{
		map[x][y] = '^';
		run(x+1, y);
		run(x-1, y);
		run(x, y+1);
		run(x, y-1);
	}
}

int main()
{
	char s[1000];
	int start_x, start_y;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++){
		scanf("%s", s);
		for(int j = 0; j < n; j++){
			if(s[j] == 'e'){
				start_x = i;
				start_y = j;
			}
			map[i][j] = s[j];
		}
	}
	run(start_x, start_y);
	if(DONE) printf("Alive!\n");
	else printf("Dead!\n");
	return 0;
}
