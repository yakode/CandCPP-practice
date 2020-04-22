#include <iostream>
#include <algorithm>
int main(){
	int n, x[10000+5];
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> x[i];

	//bubble sort
	for(int i = 0; i < n-1; i++){
		for(int j = 1; j < n-i-1; j++){
			if(x[j] < x[j+1])
				std::swap(x[j], x[j+1]);
		}
	}

	//output
	for(int i = 0; i < n-1; i++)
		std::cout << x[i] << ' ';
	std::cout << x[n-1] << std::endl;
	return 0;
}
