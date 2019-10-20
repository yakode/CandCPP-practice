#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

void rotateList(Node **head, int k){
	Node *ptr = *head;
	for(int i = 0; i < k-1; i++) ptr = ptr->next;
	Node *tmp = ptr;
	if(ptr->next != NULL){
		ptr = ptr->next;
		tmp->next = NULL;
		tmp = ptr;
		while(ptr->next != NULL) ptr = ptr->next;
		ptr->next = *head;
		*head = tmp;

	}
}

void freeList(Node *head);
Node* createList();
void printList(Node *head);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;
	int k;

    head = createList();
	scanf("%d",&k);	
	rotateList(&head,k);
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

Node* createList(){
    Node* head = NULL;
    Node* temp = NULL;
    int data;

    while(1){
        scanf("%d",&data);
        if(data>-1){
            if (temp==NULL) {
                temp = (Node*) malloc(sizeof(Node));
                head = temp;
            } else {
                temp->next = (Node*) malloc(sizeof(Node));
                temp = temp->next;
            }
            temp->data = data;
            temp->next = NULL;
        } else break;
    }
    return head;
}

void printList(Node *head)
{
	Node *temp=head;
	printf("%d", temp->data);
	temp=temp->next;
	
	for(; temp!=NULL; temp=temp->next)
	{
		printf(" %d", temp->data);
	}
	printf("\n");
}
