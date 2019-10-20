#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string cmd;
	int num;
	vector<int> heap;
	while(cin >> cmd){
		if(cmd == "PUSH"){
			cin >> num;
			heap.push_back(num);
		}else if(cmd == "POP" && !heap.empty()){
			if(!is_heap(heap.begin(), heap.end())){
				make_heap(heap.begin(), heap.end());
			}
			pop_heap(heap.begin(), heap.end());
			heap.pop_back();
		}else if(cmd == "TOP" && !heap.empty()){
			if(!is_heap(heap.begin(), heap.end())){
				make_heap(heap.begin(), heap.end());
			}
			cout << heap.front() << endl;
		}else if(cmd == "TOP" && heap.empty()){
			cout << "Null" << endl;
		}
	}
	return 0;
}
