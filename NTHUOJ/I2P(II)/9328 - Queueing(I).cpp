#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main(){
	queue<string> q;
	string cmd, s;
	while(cin >> cmd){
		if(cmd == "Push"){
			cin >> s;
			q.push(s);
		}else if(cmd == "Pop"){
			if(!q.empty()){
				q.pop();
			}
		}else if(cmd == "Front"){
			if(!q.empty()){
				cout << q.front() << endl;
			}else{
				cout << "empty" << endl;
			}
		}
	}
	return 0;
}
