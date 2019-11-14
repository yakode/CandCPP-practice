#include <iostream>
using namespace std;

int main(){
	int N;
	int A[10][10];
	char E[10];
	cin >> N;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> A[i][j];
	cin >> E;

	for(int k = 0; k < N; ++k)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if(A[i][j] || (A[i][k] && A[k][j]))
					A[i][j] = 1;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << A[i][j];
			if(j != N-1) cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
