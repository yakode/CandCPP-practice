#include <iostream>
#include <cstdio>
using namespace std;
int time_merge = 0;


void merge_sort(int *arr, int begin, int end){
	if(begin >= end) return;
	int middle = (begin+end) / 2;
	merge_sort(arr, begin, middle);
	merge_sort(arr, middle+1, end);

	time_merge++;
	//merge
	int ptr1 = begin, ptr2 = middle+1;
	int *tmp = new int[end-begin+5];
	int index = 0;
	while(ptr1 != middle+1 && ptr2 != end+1){
		if(arr[ptr1] < arr[ptr2])
			tmp[index++] = arr[ptr1++];
		else
			tmp[index++] = arr[ptr2++];
	}
	while(ptr1 != middle+1) tmp[index++] = arr[ptr1++];
	while(ptr2 != end+1) tmp[index++] = arr[ptr2++];
	for(int i = begin, j = 0; i <= end; ++i, ++j)
		arr[i] = tmp[j];

	delete []tmp;
}

int main(){
	int arr[10000];
	char c;
	int N = 0;
	while(cin >> arr[N++]);
	N--;
	/*do{
		cin >> arr[N++];
		c = getchar();
	}while(c != '\n');*/
	merge_sort(arr, 0, N-1);
	for(int i = 0; i < N; ++i) cout << arr[i] << ' ';
	cout << '\n';
	cout << time_merge << '\n';
	return 0;
}
