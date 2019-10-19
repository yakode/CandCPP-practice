#include <iostream>
int h, w;
int board[25][25];
int mini_step;
int dx[4] = {0, 0, 1, -1},
	dy[4] = {1, -1, 0, 0};

// 0:vacant square, 1:block, 2:start pos, 3: goal pos
void dfs(int x, int y, int dir, int step){
	if(step > 10) return;

	x += dx[dir];
	y += dy[dir];
	while(x >= 0 && x < h && y >= 0 && y < w){
		if(board[x][y] == 3){
			if(step < mini_step || mini_step == -1) mini_step = step;
			return;
		}else if(board[x][y] == 1){
			board[x][y] = 0;
			x -= dx[dir];
			y -= dy[dir];
			for(int i = 0; i < 4; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx >= 0 && ny >= 0 && nx < h && ny < w && board[nx][ny] != 1){
					dfs(x, y, i, step+1);
				}
			}
			board[x+dx[dir]][y+dy[dir]] = 1;
			return;
		}

		x += dx[dir];
		y += dy[dir];
	}	
}

using namespace std;
int main(){
	while(1){
		cin >> w >> h;
		if(h == 0 && w == 0) break;
		
		int sx, sy;
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cin >> board[i][j];
				if(board[i][j] == 2){
					sx = i;
					sy = j;
				}
			}
		}

		mini_step = -1;
		for(int i = 0; i < 4; i++){
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if(nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] != 1)
				dfs(sx, sy, i, 1);
		}

		cout << mini_step << endl;
	}
}
