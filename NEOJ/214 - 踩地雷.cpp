#include <iostream>

int main(){
	int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},
					  {0, -1}, {0, 1} ,
					  {1, -1}, {1, 0}, {1, 1} };
	int n, m, map[100][100], ans[100][100];
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> map[i][j];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int sum = 0;
			for(int k = 0; k < 8; k++){
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if((x >= 0 && x < n) && (y >= 0 && y < m))
					sum += map[x][y];
			}
			ans[i][j] = sum;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			std::cout << ans[i][j];
			if(j != m-1) std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
