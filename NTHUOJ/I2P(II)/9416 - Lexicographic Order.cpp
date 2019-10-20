#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	string s;
	vector<string> v;
	while(cin >> N){
		if(N == 0) break;
		for(int i = 0; i < N; i++){
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for(auto a : v){
			cout << a << endl;
		}
		v.clear();
		cout << endl;
	}
	return 0;
}
