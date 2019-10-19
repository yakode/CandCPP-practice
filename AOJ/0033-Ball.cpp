#include <iostream>
int ball_A[11], ball_B[10], ball_C[10];

//pa what will put
//pb, pc are empty
bool dfs(int pa, int pb, int pc){
	if(pa == 10) return true;
	
	bool result_B = false;
	bool result_C = false;
	if(pb == 0 || ball_A[pa] > ball_B[pb-1]){
		ball_B[pb] = ball_A[pa];
		result_B = dfs(pa+1, pb+1, pc);
	}
	if(pc == 0 || ball_A[pa] > ball_C[pc-1]){
		ball_C[pc] = ball_A[pa];
		result_C = dfs(pa+1, pb, pc+1);
	}
	return result_B || result_C;
}

using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		for(int i = 0; i < 10; i++) cin >> ball_A[i];
		bool ans = false;
		ans = dfs(0, 0, 0);
		if(ans == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
