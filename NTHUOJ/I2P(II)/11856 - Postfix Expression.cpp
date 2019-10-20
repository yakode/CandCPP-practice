#include <iostream>
#include <stack>
using namespace std;

int main(){
	char c[10];
	int a, b;
	stack<int> digit;
	while(cin >> c){
		if(c[0] == '0') break;
		if(c[0] == '+'){
			a = digit.top();
			digit.pop();
			b = digit.top();
			digit.pop();
			digit.push(a+b);
		}else if(c[0] == '-'){
			a = digit.top();
			digit.pop();
			b = digit.top();
			digit.pop();
			digit.push(b-a);
		}else if(c[0] == '*'){
			a = digit.top();
			digit.pop();
			b = digit.top();
			digit.pop();
			digit.push(a*b);
		}else if(c[0] == '/'){
			a = digit.top();
			digit.pop();
			b = digit.top();
			digit.pop();
			digit.push(b/a);
		}else{
			int i = atoi(c);
			digit.push(i);
		}
	}
	cout << digit.top() << '\n';
	return 0;
}
