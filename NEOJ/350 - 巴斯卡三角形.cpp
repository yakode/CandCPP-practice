#include<iostream>
int ba[100][100];

int basica(int n, int m){
	if(m == 1 || m == n) return 1;
	else if (ba[n][m] == 0){
		ba[n][m] = basica(n-1, m) + basica(n-1, m-1);
	} 
	return ba[n][m];
} 

int main(){
	int T;
	std::cin >> T;
	while(T--){
		int n, m;
		std::cin >> n >> m;
		std::cout << basica(n, m) << std::endl;
	}
	return 0;
}
