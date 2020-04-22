#include <iostream>

int main(){
	char s[501];
	std::cin >> s;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i]+3 <= 'z')
			s[i] = s[i] + 3;
		else
			s[i] = (s[i] + 3) - 26;
	}
	std::cout << s << std::endl;
	return 0;
}
