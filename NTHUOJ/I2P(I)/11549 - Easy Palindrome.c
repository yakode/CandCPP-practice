#include <stdio.h>

int main(){
	double input;
	scanf("%lf",&input);
	input *= 1000;
	int num = input;
	int a1 = num / 1000;
	int b1 = num % 1000;
	int a2 = (a1%10)*100 + (a1-(a1/100)*100-a1%10) + (a1/100);
	int b2 = (b1%10)*100 + (b1-(b1/100)*100-b1%10) + (b1/100);
	a1 += a2;
	b1 += b2;
	if(b1 >= 1000){
		b1 -= 1000;
		a1 += 1;
	}
	printf("%d.%d",a1 ,b1);
	return 0;
}
