#include <iostream>

int main(){
	int n, s[10000];
	int i = 0;
	std::cin >> n;
	while(i < n){
		std::cin >> s[i];
		if(s[i] > 0) s[i] = 0;
		i++;
	} 
	while(i > 0){
		std::cout << s[i-1];
		std::cout << "\n";
		i--;
	}
	return 0;
}
