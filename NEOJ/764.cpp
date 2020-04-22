#include <iostream>

int main(){
    int N, D, f, l;
    std::cin >> N >> D;

	int i = 0;
    while(i < N){
		int j = 0;
		int sum = 0;
        while(j < D){
            std::cin >> f >> l;
            if(l-f < 8)
				sum++;
			j++;
        }
        std::cout << sum * 100 / D << std::endl;
		i++;
    }
    return 0;
}



