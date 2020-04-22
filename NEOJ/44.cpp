#include <iostream>
#include <cstring>
#include <queue>
char map[105][105];
int N;
int dx[4] = {1, -1, 0, 0},
	dy[4] = {0, 0, 1, -1};
//# wall, . road, K cat, @ mouse

int bfs(int sx, int sy){
	std::queue <int> qx, qy;
	qx.push(sx);
	qy.push(sy);
	int d[105][105] = {0};
	d[sx][sy] = 0;
	while(qx.size()){
		int x = qx.front(),
			y = qy.front();
		qx.pop();
		qy.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i],
				ny = y + dy[i];	
			if(map[nx][ny] == '@') return d[x][y] + 1;
			else if(map[nx][ny] == '.'){
				map[nx][ny] = '#';
				qx.push(nx);
				qy.push(ny);
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}
	//cannot find
	return 0;
}


using namespace std;
int main(){
	while(1){
		cin >> N;
		if(N == 0) break;

		//input map
		for(int i = 0; i < N; i++) cin >> map[i];
		//find cat
		int M = strlen(map[0]);
		int sx, sy;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				if(map[i][j] == 'K'){
					sx = i;
					sy = j;
				}
			}
		}
		
		int ans = bfs(sx, sy);
		if(ans == 0) cout << "= =\"" << endl;
		else cout << ans << endl;
	}
	return 0;
}
