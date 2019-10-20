#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[30];
	int score;
	int order;
} Record;

Record student[100000];

int cmp(const void *a, const void *b){
	Record* sa = (Record*) a;
	Record* sb = (Record*) b;
	if(sa->score < sb->score) return 1;
	if(sa->score > sb->score) return 0;
	if(sa->order > sb->order) return 1;
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s%d", student[i].name, &student[i].score);
		student[i].order = i;
	}

	qsort(student, n, sizeof(Record), cmp);

	for(int i = 0; i < n; i++)
		printf("%s\n", student[i].name);
	
	return 0;
}
