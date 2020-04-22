#include <iostream>

int main(){
	int N, M;
	std::cin >> N;
	M = N + (N + 5);
	M *= (N + 4); // M = M * (N + 4);
	M /= 8; // M = M / 8;
	M -= (N - 7); // M = M - (N - 7);
	M %= N; // M = M % N;
	std::cout << "I got " << M << " dollars today!" << std::endl;
	return 0;
}



