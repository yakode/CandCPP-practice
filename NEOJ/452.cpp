#include <iostream>

int main(){
	int N;
	int arr[100000];
	std::cin >> N;
	for(int i = 0; i < N; i++)
		std::cin >> arr[i];
	for(int i = 0; i < N; i += 2){
		if(i+2 < N)
			std::cout << arr[i] << " ";
		else std::cout << arr[i] << std::endl;
	}
	for(int i = 1; i < N; i += 2){
		if(i+2 < N)
			std::cout << arr[i] << " ";
		else std::cout << arr[i] << std::endl;
	}
	return 0;
}
