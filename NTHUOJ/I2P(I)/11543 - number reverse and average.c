#include <stdio.h>

int main(){
	int num;
	scanf("%d",&num);
	int reverse = (num%10)*100 + (num-(num/100)*100-num%10) + (num/100);
	float ans = (reverse+num)/2;
	if((reverse+num)%2 != 0) ans += 0.5;
	printf("%.1f",ans);
	return 0;
}
