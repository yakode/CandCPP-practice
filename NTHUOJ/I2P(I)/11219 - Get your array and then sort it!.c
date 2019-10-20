#include <stdio.h>
#include <stdlib.h>

int* readInput() {
    int i, N, *seq;
    scanf("%d", &N);
    seq = (int*)malloc(sizeof(int)*(N + 1));
    seq[0] = N;
    for(i=1; i<N+1; i++)
        scanf("%d", &seq[i]);
    return seq;
}

int cmp(const void* a, const void* b){
	const int * ia = (const int *) a;
	const int * ib = (const int *) b;
	return *ia - *ib;
}

void my_sort(int* B){
	int *p =(int *) *B;	
	int len = *p;
	qsort(p+1, len, sizeof(int), cmp);
}

int main() {
    int i;
    int *A = readInput();
    my_sort((int*)&A);
    printf("%d", A[1]);
    for(i=2;i<A[0]+1;i++)
        printf(" %d", A[i]);
    printf("\n");
    return 0;
}

