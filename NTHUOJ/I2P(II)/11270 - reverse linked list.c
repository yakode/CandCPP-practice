#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void printList(Node *head);
void freeList(Node*);

Node* createList(){
	Node *head = NULL, *ptr = NULL;
	int x;
	while(scanf("%d", &x) == 1){
		if(x == -1) break;
		if(ptr == NULL){ 
			ptr = (Node*)malloc(sizeof(Node));
			head = ptr;
		}
		else{
			ptr->next = (Node*)malloc(sizeof(Node));
			ptr = ptr->next;
		}
		ptr->next = NULL;
		ptr->data = x;
	}
	return head;
}

Node* reverse(Node* head){
	Node *_pre = NULL, *_now = head, *_next = head->next;
	_now->next = NULL;
	_pre = _now;
	_now = _next;
	_next = _next->next;
	while(_now->next != NULL){
		_now->next = _pre;
		_pre = _now;
		_now = _next;
		if(_next != NULL) _next = _next->next;
	}
	_now->next = _pre;
	return _now;
}

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

    head = createList();
	printList(head);
	head = reverse(head);
	printList(head);
	freeList(head);
	return 0;
}



void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}

