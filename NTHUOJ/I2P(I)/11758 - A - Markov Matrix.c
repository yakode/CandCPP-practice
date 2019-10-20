#include <stdio.h>

void show(double arr[10],int n){
	for(int i = 0; i < n; i++)
		printf("%lf ", arr[i]);
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		double A[10][10];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%lf", &A[i][j]);
		double x[10];
		for(int i = 0; i < n; i++)
			scanf("%lf", &x[i]);
		double p;
		scanf("%lf", &p);

		int year = 0;
		while(x[0] > p){
			year++;
			int flag = 1;
			double tmp[10] = {};
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					tmp[i] += A[i][j] * x[j];
				}
				if(tmp[0] >= x[0]) {
					flag = 0;
					break;
				}
			}
			if(flag)
				for(int i = 0; i < n; i++)
					x[i] = tmp[i];
			else{
				year = -1;
				break;
			}
		}
		
		if(year == -1)
			printf("Never\n");
		else
			printf("%d\n", year);
	}

	return 0;
}
