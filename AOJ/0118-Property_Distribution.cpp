#include <iostream>
char map[105][105];
int H, W;
int dx[4] = {0, 0, 1, -1},
	dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, char c){
	map[x][y] = '.';
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i],
			ny = y + dy[i];
		if(nx >= 0 && nx < H && ny >= 0 && ny < W && map[nx][ny] == c)
			dfs(nx, ny, c);
	}
}


using namespace std;
int main(){
	while(1){
		cin >> H >> W;
		if(H == 0 && W == 0) break;

		for(int i = 0; i < H; ++i) cin >> map[i];
		int ans = 0;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(map[i][j] != '.'){
					ans++;
					dfs(i, j, map[i][j]);
				}
			}
		}
		cout << ans << endl;
	}
}
