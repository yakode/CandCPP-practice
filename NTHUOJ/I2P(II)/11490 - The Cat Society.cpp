#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Cat{
	string name;
	int rank;
	int age;
}cats[10000];

bool cmp(Cat a, Cat b){
	if(a.rank != b.rank) return a.rank < b.rank;
	if(a.age != b.age){
		if(a.rank != 5) return a.age > b.age;
		else return a.age < b.age;
	}
	return a.name < b.name;
}

int main(){
	int N, M;	
	string occupation;
	ios_base::sync_with_stdio(false);
	while(cin >> N >> M){
		if(N < M) M = N;
		for(int i = 0; i < N; i++){
			cin >> cats[i].name >> occupation >> cats[i].age;
			if(occupation == "elder") cats[i].rank = 1;
			else if(occupation == "nursy") cats[i].rank = 2;
			else if(occupation == "kitty") cats[i].rank = 3;
			else if(occupation == "warrior") cats[i].rank = 4;
			else if(occupation == "apprentice") cats[i].rank = 5;
			else if(occupation == "medicent") cats[i].rank = 6;
			else if(occupation == "deputy") cats[i].rank = 7;
			else if(occupation == "leader") cats[i].rank = 8;
		}

		sort(cats, cats+N, cmp);
	
		for(int i = 0; i < M; i++){
			cout << cats[i].name << '\n';
		}
	}
	
	return 0;
}

