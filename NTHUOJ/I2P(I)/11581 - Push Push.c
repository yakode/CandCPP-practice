#include <stdio.h>

int main(){
	int num1, num2;
	scanf("%d",&num1);
	num2 = (num1%10)*1000 + (num1/10);
	printf("%d",num1+num2);
	return 0;
}
