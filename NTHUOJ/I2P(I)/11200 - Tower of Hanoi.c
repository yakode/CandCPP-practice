#include <stdio.h>

void hanoi(int from, int to, int buff, int n){
	if(n <= 0) return;
	hanoi(from, buff, to, n-1);
	printf("%d\n", n);
	hanoi(buff, to, from, n-1);
} 

int main(){
    int n;
    scanf("%d", &n);
    hanoi(1, 3, 2, n);
    return 0;
}
