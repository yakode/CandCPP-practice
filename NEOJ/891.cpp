#include <iostream>

int main(){
	int n, m;
	std::cin >> n >> m;
	int n_m = 1;
	for(int i = 0; i < m; i++) n_m *= n;
	int n_m_ = 1;
	for(int i = n; i > m; i--) n_m_ *= i;
	std::cout << n_m + n_m_ << std::endl;
	return 0;
}
