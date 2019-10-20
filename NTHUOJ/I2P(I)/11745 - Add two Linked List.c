#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

void Create_List(Node** head, int x){
	if(*head == NULL){
		*head = (Node*) malloc(sizeof(Node));
		(*head) -> next = NULL;
		(*head) -> data = x;
	}
	else{
		Node* ptr = (*head);
		while(ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = (Node*) malloc(sizeof(Node));
		ptr -> next -> data = x;
		ptr -> next -> next = NULL;
	}
}

Node* Add_List(Node* head_a, Node* head_b){
	Node *head = NULL, *ptr = NULL;
	while(head_a != NULL || head_b != NULL){
		int a = 0, b = 0, num;
		if(head_a != NULL){
			a = head_a -> data;
			head_a = head_a -> next;
		}
		if(head_b != NULL){
			b = head_b -> data;
			head_b = head_b -> next;
		}

		num = a + b;

		if(ptr == NULL){
			ptr = (Node*) malloc(sizeof(Node));
			ptr -> data = num;
			ptr -> next = NULL;
			head = ptr;
		}
		else{
			ptr -> next = (Node*) malloc(sizeof(Node));
			ptr = ptr -> next;
			ptr -> next = NULL;
			ptr -> data = num;
		}
	}
	return head;
}

void Print_List(Node* ptr){
	if(ptr == NULL) return;
	printf("%d", ptr->data);
	if(ptr->next != NULL){
		printf("->");
		Print_List(ptr->next);
	}
	else printf("\n");
}

void Free_List(Node* ptr){
	free(ptr);
}

int main() {
    Node *head_a = NULL, *head_b = NULL;
    int data;

    while(1) { // read List a
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_a, data);
        } else break;
    }
    while(1) { // read List b
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_b, data);
        } else break;
    }
    
    Node *head = Add_List( head_a, head_b );
    
    Print_List( head_a );
    Print_List( head_b );
    Print_List( head );
    
    Free_List( head_a );
    Free_List( head_b );
    Free_List( head );
    
    return 0;
}


