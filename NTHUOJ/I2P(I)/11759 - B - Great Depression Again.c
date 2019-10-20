#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	int A, B;
} Fac;
Fac fac[200000];
int n, x, y;
int list_A[200000], list_B[200000];

int cmp0 (const void* a, const void* b){
	Fac* fa = (Fac*) a;
	Fac* fb = (Fac*) b;
	if( (fa->A - fa->B) < (fb->A - fb->B) ) return 1;
	else return 0;
}

int cmp1 (const void* a, const void* b){
	int* ia = (int*) a;
	int* ib = (int*) b;
	if(fac[*ia].A < fac[*ib].A) return 1;
	else return 0;
}

int cmp2 (const void* a, const void* b){
	int* ia = (int*) a;
	int* ib = (int*) b;
	if(fac[*ia].B < fac[*ib].B) return 1;
	else return 0;
}

int cmp3 (const void* a, const void* b){
	int* ia = (int*) a;
	int* ib = (int*) b;
	if(strcmp(fac[*ia].name, fac[*ib].name) > 0) return 1;
	else return 0;
}

long long int split(int mid){
	int index = 0;
	for(int i = 0; i < mid; i++) list_A[index++] = i;
	index = 0;
	for(int i = mid; i < n; i++) list_B[index++] = i;

	qsort(list_A, mid, sizeof(int), cmp1);
	qsort(list_B, (n-mid), sizeof(int), cmp2);

	long long int ans = 0;
	for(int i = 0; i < x; i++) ans += fac[list_A[i]].A;
	for(int i = 0; i < y; i++) ans += fac[list_B[i]].B;
	
	return ans;
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 0; i < n; i++)
		scanf("%s%d%d", fac[i].name, &fac[i].A, &fac[i].B);
	qsort(fac, n, sizeof(Fac), cmp0);
	
	// mid x -> n - y
	int mid = -1;
	long long int max = -1;
	for(int i = x; i <= n - y; i++){
		int tmp = split(i);
		if(tmp > max){
			max = tmp;
			mid = i;
		}
	}

	split(mid);
	qsort(list_A, x, sizeof(int), cmp3);
	for(int i = 0; i < x; i++) printf("%s\n", fac[list_A[i]].name);
	return 0;
}
