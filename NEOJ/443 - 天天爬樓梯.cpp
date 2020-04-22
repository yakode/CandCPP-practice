#include <iostream>

int ladder(int n);

int go[100] = {};

int ladder(int n){
	if(n == 0) return 1;
	if(n < 0) return 0;
	if(go[n] == 0) go[n] = ladder(n-1) + ladder(n-2) + ladder(n-3);
	return go[n];
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << ladder(n) << '\n';
	return 0;
}
