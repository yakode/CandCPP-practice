#include <iostream>

int main(){
	int r1, r2;
	int pi = 3;
	std::cin >> r1 >> r2;
	int ans = 4 * pi * (r1 * r1 + r2 * r2);
	std::cout << ans;
	return 0;
}
