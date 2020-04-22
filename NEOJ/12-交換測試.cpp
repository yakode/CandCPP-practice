#include <iostream>
int main() {
    int a, b;
    std::cin >> a >> b;
    int c = a;
	a = b;
	b = c;
    std::cout << a << " " << b; 
}
