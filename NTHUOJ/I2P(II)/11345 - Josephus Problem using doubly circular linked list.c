#include <stdio.h>
#include <stdlib.h>

typedef struct man {
    int id;
    struct man* next;
    struct man* prev;
} man;

man* head;
man* createList(int n);
int solveJosephus(int step);

void show(man* head){
	man* ptr = head;
	while(ptr->next != head){ 
		printf("%d ", ptr->id);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->id);
}

int main(){

    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus(m));
    }

    return 0;
}

man* createList(int n){ 
    int i;
    man* curr;
    head = (man*)malloc(sizeof(man));
    curr = head;
    curr->id = 1;
    for(i=2; i<=n; i++){
        curr->next = (man*)malloc(sizeof(man));
        curr->next->prev = curr;
        curr = curr->next;
        curr->id = i;
    }
    curr->next = head;
    head->prev = curr;

    return head;
}


int solveJosephus(int step){
	man* ptr = head->prev;
	while(ptr->next != ptr){
		//show(ptr);
		for(int i = 0; i < step; i++) ptr = ptr->next;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ptr = ptr->next;
		for(int i = 0; i < step; i++) ptr = ptr->prev;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		man* tmp = ptr;
		ptr = ptr->prev;
		if(ptr->next!=ptr)free(tmp);
	}
	return ptr->id;
}
