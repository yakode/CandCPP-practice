#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;

int compare_a(const void *a, const void *b){
	const Grade *ga = (const Grade *) a;
    const Grade *gb = (const Grade *) b;
	if(ga -> total > gb -> total) return 1;
	else if(gb -> total > ga -> total) return 0;
	if(ga -> Chinese > gb -> Chinese) return 1;
	else if(gb -> Chinese > ga -> Chinese) return 0;
	if(ga -> English > gb -> English) return 1;
	else if(gb -> English > ga -> English) return 0;
	if(ga -> math > gb -> math) return 1;
	else if(gb -> math > ga -> math) return 0;
	if(ga -> science > gb -> science) return 1;
	else if(gb -> science > ga -> science) return 0;
	if(ga -> ID > gb -> ID) return 1;
	return 0;
}

int compare_d(const void *a, const void *b){
	const Grade *ga = (const Grade *) a;
    const Grade *gb = (const Grade *) b;
	if(ga -> total < gb -> total) return 1;
	else if(gb -> total < ga -> total) return 0;
	if(ga -> Chinese < gb -> Chinese) return 1;
	else if(gb -> Chinese < ga -> Chinese) return 0;
	if(ga -> English < gb -> English) return 1;
	else if(gb -> English < ga -> English) return 0;
	if(ga -> math < gb -> math) return 1;
	else if(gb -> math < ga -> math) return 0;
	if(ga -> science < gb -> science) return 1;
	else if(gb -> science < ga -> science) return 0;
	if(ga -> ID > gb -> ID) return 1;
	return 0;
}

void sortGrade(Grade *gList, int n, char *order){
	for(int i = 0; i < n; i++)
		gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;

	if(order[0] == 97){
		qsort(gList, n, sizeof(Grade), compare_a);
	}
	else{
		qsort(gList, n, sizeof(Grade), compare_d);
	}
}

int main(){
    int n, i;
    char order[20];
    Grade gradeList[1000];
    scanf("%d%s", &n, order);
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
    sortGrade(gradeList, n, order);
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
    return 0;
}

