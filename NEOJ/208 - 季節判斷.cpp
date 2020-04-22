#include <iostream>

int main(){
	int month;
	std::cin >> month;
	if(month < 4)
		std::cout << "spring" << std::endl;
	else if(month < 7)
		std::cout << "summer" << std::endl;
	else if(month < 10)
		std::cout << "fall" << std::endl;
	else
		std::cout << "winter" << std::endl;
	return 0;
} 
