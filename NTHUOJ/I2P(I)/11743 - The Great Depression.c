#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[30];
	int a, b;
	int diff;
}Car;

int cmp(const void *a, const void *b){
	Car* ca = (Car*) a;
	Car* cb = (Car*) b;
	if(ca->diff < cb->diff) return 1;
	else return 0;
}

int lexico(const void *a, const void *b){
	Car* ca = (Car*) a;
	Car* cb = (Car*) b;
	if(strcmp(ca->name, cb->name) > 0) return 1;
	else return 0;
}


int main(){
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	Car* cars = (Car*) malloc(n*sizeof(Car));
	for(int i = 0; i < n; i++){
		scanf("%s%d%d", &cars[i].name, &cars[i].a, &cars[i].b);
		cars[i].diff = cars[i].a - cars[i].b;
	}
	qsort(cars, n, sizeof(Car), cmp);
	qsort(cars, x, sizeof(Car), lexico);
	for(int i = 0; i < x; i++)
		printf("%s\n", cars[i].name);
	return 0;
}
