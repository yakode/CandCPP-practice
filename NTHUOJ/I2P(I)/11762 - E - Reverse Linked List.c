#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* tail = NULL;

Node* Create_List(Node* head, int x){
	if(head == NULL){
		head = (Node*) malloc(sizeof(Node));
		head -> data = x;
		head -> next = NULL;
		tail = head;
	}
	else{
		tail -> next = (Node*) malloc(sizeof(Node));
		tail = tail -> next;
		tail -> next = NULL;
		tail -> data = x;
	}
	return head;
}
Node* Reverse_List(Node* head){
	Node* tmp = NULL;
	Node* pre = NULL;
	pre = head;
	head = head -> next;
	pre -> next = NULL;
	while(head != NULL){
		tmp = head -> next;
		head -> next = pre;
		pre = head;
		head = tmp;

	}
	return tail;
}
void Print_List(Node* head){
	while(head != NULL){
		if(head -> next != NULL)
			printf("%d->", head -> data);
		else
			printf("%d\n", head -> data);
		head = head -> next;
	}
}
void Free_List(Node* head){
	Node* pre;
	while(head != NULL){
		pre = head;
		head = head -> next;
		free(pre);
	}
}

int main() {
    Node *head = NULL;
    int n, data, i;
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }
    
    head = Reverse_List( head );
    
    Print_List( head );
    Free_List( head );
    
    return 0;
}

