#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	string name;
	vector<Node*> kid;
};

bool is_over;
vector<string> ans;

void omg(Node* start, set<string> girl, vector<string> name){
	if(is_over) return;
	int sz = start->kid.size();
	if(girl.count(start->name) == 0){
		ans = name;
		is_over = true;
	}else if(sz == 0){
		return;
	}else{
		girl.erase(start->name);
		name.push_back(start->name);
		for(int i = 0; i < sz; i++){
			omg(start->kid[i], girl, name);
		}
	}
}

int main(){
	set<string> girl;
	map<string, Node*> index;
	vector<string> person;
	int P;
	string n, m;
	cin >> P;
	for(int i = 0; i < P; i++){
		cin >> n >> m;
		Node *ptrn, *ptrm;
		if(girl.count(n) == 0){
			ptrn = new Node;
			ptrn->name = n;
			girl.insert(n);
			index.insert(pair<string, Node*>(n, ptrn));
			person.push_back(n);
		}
		if(girl.count(m) == 0){
			ptrm = new Node;
			ptrm->name = m;
			girl.insert(m);
			index.insert(pair<string, Node*>(m, ptrm));
			person.push_back(m);
		}
		ptrn = index[n];
		ptrm = index[m];
		ptrm->kid.push_back(ptrn);
	}
	ans.clear();
	is_over = false;
	for(auto k : person){
		//cout << index[k]->name << '\n';
		if(is_over) break;
		omg(index[k], girl, ans);
		if(ans.size() != 0) break;
	}
	sort(ans.begin(), ans.end());
	for(auto k : ans){
		cout << k << '\n';
	}
	return 0;
}
