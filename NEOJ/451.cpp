#include <iostream>

int main(){
	int d, w;
    std::cin >> d >> w ;

    if(d > 31 || d < 1 || w < 1 || w > 7){
	    std::cout << "= =" << std::endl;
	} else if(d == 13 && w == 5){
   	    std::cout << "._.zZ" << std::endl;
    } else if(d == 13){
   	    std::cout << "QAQ" << std::endl;
    } else{
   	    std::cout << "Oh,AC!" << std::endl;
    }

	return 0;
}
