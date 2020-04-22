#include <iostream>

int main(){
	int x, y;
	char trash;
	std::cin >> trash >> x >> trash >> y >> trash;
	std::cout<< "(" << (x+3)*2 << "," << (x+y)*2 << ")" << std::endl;
	return 0;
}



