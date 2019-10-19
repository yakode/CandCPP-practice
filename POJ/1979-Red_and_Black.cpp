#include <iostream>
char map[25][25];
int H, W;
int dx[4] = {0, 0, 1, -1},
	dy[4] = {1, -1, 0, 0};

int dfs(int count, int x, int y){
	map[x][y] = '#';
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i],
			ny = y + dy[i];
		if(nx >= 0 && nx < H && ny >= 0 && ny < W && map[nx][ny] == '.'){
			count = dfs(count, nx, ny);	
		}
	}
	return count+1;
}


using namespace std;
int main(){
	while(1){
		cin >> W >> H;
		if(W == 0 && H == 0) break;

		for(int i = 0; i < H; ++i) cin >> map[i];
		int done = 0;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(map[i][j] == '@'){
					cout << dfs(0, i, j) << endl;
					done = 1;
					break;
				}
			}
			if(done == 1) break;
		}
	}
	return 0;
}
