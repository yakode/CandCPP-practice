#include <iostream>

int main(){
	int n;
	int sum = 1;
	std::cin >> n;
	n ++;
	while( --n ) sum *= n;
	std::cout << sum << std::endl;
	return 0;
}
