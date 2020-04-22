#include <iostream>

int main(){
	int N, g[100], sum = 0, average;
	int i = 0;
	std::cin >> N;
	while(i < N){
		std::cin >> g[i];
		sum += g[i];
		i++;
	}
	average = sum / N;
	sum = 0;
	i = 0;
	while(i < N){
		if(g[i] < average) sum += g[i];
		i++;
	}
	std::cout << sum;
	return 0;
}
