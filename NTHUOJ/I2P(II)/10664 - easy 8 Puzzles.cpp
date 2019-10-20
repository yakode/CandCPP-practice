#include <iostream>
#include <set>
#include <queue>
using namespace std;

using board = vector<int>;


bool check(board cb){
	for(int i = 0; i < 8; i++){
		if(cb[i] != i+1) return false;
	}
	return true;
}


int bfs(board ss, int sx){
	set<board> state;
	queue<board> qs;
	queue<int> qx;
	qs.push(ss);
	qx.push(sx);
	state.insert(ss);
	
	int x;
	board s;
	int step = 0;
	while(!qx.empty()){
		int sz = qx.size();
		while(sz--){
			x = qx.front();
			qx.pop();
			s = qs.front();
			qs.pop();
			//show(s);
			if(check(s)) return step;
	
			if(x%3 != 0){
				//left
				swap(s[x], s[x-1]);
				if(state.count(s) == 0){
					qx.push(x-1);
					qs.push(s);
					state.insert(s);
				}
				swap(s[x], s[x-1]);
			}
			if((x+1)%3 != 0){
				//right
				swap(s[x], s[x+1]);
				if(state.count(s) == 0){
					qx.push(x+1);
					qs.push(s);
					state.insert(s);
				}
				swap(s[x], s[x+1]);
			}
			if(x > 2){
				//up
				swap(s[x], s[x-3]);
				if(state.count(s) == 0){
					qx.push(x-3);
					qs.push(s);
					state.insert(s);
				}
				swap(s[x], s[x-3]);
			}
			if(x < 6){
				//down
				swap(s[x], s[x+3]);
				if(state.count(s) == 0){
					qx.push(x+3);
					qs.push(s);
					state.insert(s);
				}
				swap(s[x], s[x+3]);
			}
		}
		if(step == 14) return -1;
		++step;
	}
	return -1;
}

int main(){
	int T, sx, nums;
	cin >> T;
	while(T--){
		board state_now;
		for(int i = 0; i < 9; i++){
			cin >> nums;
			state_now.push_back(nums);
			if(state_now[i] == 0) sx = i;
		}
		int ans = bfs(state_now, sx);
		if(ans == -1) cout << "You'd better skip this game.\n";
		else cout << "You can solve it within " << ans << " steps.\n";
	}

	return 0;
}
