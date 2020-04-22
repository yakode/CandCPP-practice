#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int N, M;
	char spell[100][100][50];
	int section[100];

	//input spell
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> M;
		section[i] = M;
		for(int j = 0; j < M; j++){
			cin >> spell[i][j];
		}
	}
	
	//find lowest section
	for(int i = 0; i < N; i++){
		int ans = 0;

		for(int j = 0; j < N; j++){
			if(i == j) continue;
			int tmp = 0;
			for(int k = 0; k < section[i] && k < section[j]; k++){
				if(strcmp(spell[i][k], spell[j][k]) == 0){
					tmp++;
				}
				else break;
			}
			if(tmp+1 > ans) ans = tmp + 1;
			if(ans == section[i]) break;
		}

		cout << ans << endl;
	}
	return 0;
}
