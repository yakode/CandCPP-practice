#include <algorithm>
#include <cstring>

bool cmp(Student a, Student b){
	if(a.score != b.score) return a.score < b.score;
	if(strcmp(a.name, b.name) < 0) return true;
    return false;
}

void admissionListSort(Student students[], int sizeOfStudents){
	std::sort(students, students+sizeOfStudents, cmp);
}



