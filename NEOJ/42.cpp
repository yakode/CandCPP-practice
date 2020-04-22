#include <iostream>
int dx[4] = {0, 0, 1, -1},
	dy[4] = {1, -1, 0 ,0};
int H, W;
char field[1000+5][1000+5];

void dfs(int x, int y){
	field[x][y] = '#';

	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i],
			ny = y + dy[i];
		if(nx >= 0 && nx < H && ny >= 0 && ny < W && field[nx][ny] == '.')
			dfs(nx, ny);
	}
}

int main(){
	int T;
	std::cin >> T;
	while(T--){
		//input
		std::cin >> H >> W;
		for(int i = 0; i < H; ++i)
			std::cin >> field[i];
		
		//fill puddles
		int count = 0;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(field[i][j] == '.'){
					++count;
					dfs(i, j);
				}
			}
		}
			

		//output
		std::cout << count << std::endl;
	}

	return 0;
}
