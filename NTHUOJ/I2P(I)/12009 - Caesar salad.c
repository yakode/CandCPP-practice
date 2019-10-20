#include<stdio.h>

int main(){
	int n;
	char c1, c2, c3;
	scanf("%c%c%c",&c1 ,&c2 ,&c3);
	scanf("%d",&n);
	n -= (n/26) * 26;
	c1 += n;
	c2 += n;
	c3 += n;
	if(c1 > 65 + 25) c1 -= 26;
	if(c2 > 65 + 25) c2 -= 26;
	if(c3 > 65 + 25) c3 -= 26;
	if(c1 < 65) c1 += 26;
	if(c2 < 65) c2 += 26;
	if(c3 < 65) c3 += 26;
	printf("%c%c%c\n",c1 ,c2 ,c3);
	return 0;
}
