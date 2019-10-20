#include <iostream>
#include <set>
using namespace std;

int main(){
	int N;
	set<int> children;
	while(cin >> N){
		if(N == 0) break;
		int parent, child;
		for(int i = 0; i < N; i++){
			cin >> parent >> child;
			children.insert(child);
			children.erase(parent);
		}
		cin >> N; //I don't need root :)
		cout << children.size() << endl;
		children.clear();
	}
	return 0;
}
