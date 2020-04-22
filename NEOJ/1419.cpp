#include <iostream>

int n, m, arr[1000][1000];
int main(){
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> arr[i][j];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			std::cout << arr[j][i] << " ";
		std::cout << std::endl;
	}
	return 0;
}
