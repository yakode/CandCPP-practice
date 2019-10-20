#include <stdio.h>

int main(){
	int num[10];
	for(int i = 1; i < 4; i++)
		scanf("%d", &num[i]);
	if(num[2] - num[1] == num[3] - num[2]){
		int d = num[2] - num[1];
		printf("%d %d", num[1]-d, num[3]+d);
	}else{
		int r = num[2] / num[1];
		printf("%d %d", num[1]/r, num[3]*r);
	}
	return 0;
}
