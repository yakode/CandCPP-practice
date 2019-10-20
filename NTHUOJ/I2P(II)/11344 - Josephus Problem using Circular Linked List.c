#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node *next;
} Node;


Node* create(int n){
	if(n == 0) return NULL;
	Node *head, *ptr, *tmp;
	head = (Node*)malloc(sizeof(Node));
	head->data = 1;
	head->next = NULL;
	ptr = head;

	for(int i = 2; i <= n; i++){
		tmp = (Node*)malloc(sizeof(Node));
		tmp->data = i;
		ptr->next = tmp;
		ptr = tmp;	
	}

	ptr->next = head;
	return head;
}
void josephus(int m, Node *head){
	Node *tmp;
	while(head != head->next){
		for(int i = 0; i < m-2; i++) head = head->next;
		tmp = head->next;
		head->next = head->next->next;
		printf("%d ", tmp->data);
		free(tmp);
		head = head->next;
	}
	printf("%d\n", head->data);	
}

int main(void){
	int n,m;
	scanf("%u %u",&n, &m);
	josephus(m,create(n));
}
