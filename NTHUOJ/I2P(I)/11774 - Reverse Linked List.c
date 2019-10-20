#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	struct _Node *next;
} Node;

Node* Create_List (Node* head, int num){
	if(head == NULL){
		head = (Node*) malloc(sizeof(Node));
		head -> next = NULL;
		head -> data = num;
	}
	else{
		Node* tmp = (Node*) malloc(sizeof(Node));
		tmp -> next = head;
		tmp -> data = num;
		head = tmp;
	}
	return head;
}

Node* Reverse_List(Node* head){
	return head;
}

void Print_List(Node* head){
	if(head == NULL) return;
	printf("%d", head -> data);
	if(head -> next != NULL)
		printf("->");
	else
		printf("\n");
	Print_List(head->next);
}

void Free_List(Node* head){
	if(head == NULL) return;
	Free_List(head -> next);
	free(head);
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


