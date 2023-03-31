#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> node;
// first #box
// second parent box

int main(){
	vector<node> box;
	int T, n, m, q;
	int a, b;
	cin >> T;
	while(T--){
		cin >> n >> m;
		box.assign(n+1, make_pair(1, 0));
		while(m--){
			cin >> a >> b;
			box[b].second = a;
			int cnt = box[b].first;
			while(a){
				box[a].first += cnt;
				a = box[a].second;
			}
		}
		cin >> q;
		while(q--){
			cin >> a;
			cout << box[a].first << '\n';
		}
	}
	return 0;
}
