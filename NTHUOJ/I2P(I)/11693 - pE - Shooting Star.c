#include <stdio.h>
char map[100][100];
int C, F, H, S;
char dir;
int DONE;
int max;

void initial()
{
	DONE = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			map[i][j] = ' ';
		}
	}
	for(int i = 0; i < C; i++)
		map[0][i] = '-';
	for(int i = 0; i < F; i++)
		map[H+1][i] = '-';
}

void shoot(int x, int y, int direction)
{
	if(DONE) return;
	if(( x == 0 || x == (H + 1) ) && map[x][y] == ' '){
		DONE = 1;
		map[x][y] = '*';
		max = y;
		return;
	}

	if(direction){
		if(map[x][y] == ' ')
			map[x][y] = '*'; 
		if(map[x-1][y] == '-') shoot(x+1, y+1, 0);
		else shoot(x-1, y+1, 1);
	}
	else{
		if(map[x][y] == ' ')
			map[x][y] = '*'; 
		if(map[x+1][y] == '-') shoot(x-1, y+1, 1);
		else shoot(x+1, y+1, 0);
	}
}

void show()
{
	for(int i = 0; i < (H+2); i++){
		for(int j = 0; j < max; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	while(scanf("%d", &C) == 1){
		scanf("%d%d%d", &F, &H, &S);
		getchar();
		scanf("%c", &dir);
		initial();
		// up 1, down 0
		if(dir == 'u') shoot(S, 0, 1);
		else if(dir == 'd') shoot(S, 0, 0);
		max ++;
		if(C > max) max = C;
		if(F > max) max = F;
		show();
	}
}
