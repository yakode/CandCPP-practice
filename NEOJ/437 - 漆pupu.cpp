#include <iostream>

int main(){
	int R, C, T, r, c;
	int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	char map[100][100];
	std::cin >> R >> C;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			std::cin >> map[i][j];
	std::cin >> T;
	while(T--){
		std::cin >> r >> c;
		int sum = 0;
		int max = 0;
		for(int i = 0; i < 4; i++){
			if(sum > max) {
				max = sum;
			}
			sum = 0;
			if(map[r][c] == '#') continue;
			int x = r + dir[i][0];
			int y = c + dir[i][1];
			if(x < 0 || x >= R || y < 0 || y >= C) continue;
			if(map[x][y] == '#') continue;
			if(map[x][y] == '!') sum++;
			x += dir[i][0];
			y += dir[i][1];
			if(x < 0 || x >= R || y < 0 || y >= C) continue;
			if(map[x][y] == '#') continue;
			if(map[x][y] == '!') sum++;
			x += dir[i][0];
			y += dir[i][1];
			if(x < 0 || x >= R || y < 0 || y >= C) continue;
			if(map[x][y] == '!') sum++;
		}
		if(sum > max) max = sum;
		std::cout << max << std::endl;
	}
	return 0;
}
