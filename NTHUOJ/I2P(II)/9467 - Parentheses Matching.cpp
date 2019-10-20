#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	stack<char> parentheses;
	string s;
	int N;
	int k = 0;
	cin >> N;
	getchar();
	while(N--){
		k++;
		s.clear();
		getline(cin, s);
		//cin >> s;
		for(char c : s){
			if(c == '{' || c == '[' || c == '(' || c == '<'){
				parentheses.push(c);
			}else if(c == '}'){
				if(!parentheses.empty() && parentheses.top() == '{'){
					parentheses.pop();
				}else{
					parentheses.push(c);
					break;
				}
			}else if(c == ']'){
				if(!parentheses.empty() && parentheses.top() == '['){
					parentheses.pop();
				}else{
					parentheses.push(c);
					break;
				}
			}else if(c == ')'){
				if(!parentheses.empty() && parentheses.top() == '('){
					parentheses.pop();
				}else{
					parentheses.push(c);
					break;
				}
			}else if(c == '>'){
				if(!parentheses.empty() && parentheses.top() == '<'){
					parentheses.pop();
				}else{
					parentheses.push(c);
					break;
				}
			}
		}
		if(parentheses.empty())
			cout << "Case " << k << ": Yes" << endl;
		else
			cout << "Case " << k << ": No" << endl;
		while(!parentheses.empty())
			parentheses.pop();
		
	}
	return 0;
}
