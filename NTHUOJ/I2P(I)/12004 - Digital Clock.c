#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	int sec = t % 60;
	t /= 60;
	int min = t % 60;
	t /= 60;
	int hr = t;
	printf("%02d:%02d:%02d\n",hr ,min ,sec);
	return 0;
} 
