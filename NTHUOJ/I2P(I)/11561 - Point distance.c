#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int gcd(int x, int y){
	x = abs(x);
	y = abs(y);
	while(x != 0 && y != 0){
		if(x > y) x = x % y;
		else y = y % x;
	}
	return x+y;
}

int main(){
	char gar;
	int pt[3][2] = {};
	for(int i = 0; i < 3; i++){
		scanf("%c%d%c%d%c%c",&gar ,&pt[i][0] ,&gar ,&pt[i][1] ,&gar ,&gar);
	}
	int a = pt[1][1] - pt[0][1];
	int b = pt[0][0] - pt[1][0];
	int c = gcd(a,b);
	a /= c;
	b /= c;
	double son = pt[2][0] * a + pt[2][1] * b - (a * pt[0][0] + b * pt[0][1]);
	double mom = a * a + b * b;
	double ans = (son * son) / mom;
	printf("%.2f\n",ans);
	return 0;
} 
