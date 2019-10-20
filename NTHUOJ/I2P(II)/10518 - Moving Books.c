#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int id;
	struct _Node *prev;
	struct _Node *next;
}Node;
Node* ip[10000];

Node* build(int n){
	Node *head = (Node*)malloc(sizeof(Node));
	head->id = 0;
	head->prev = NULL;
	head->next = NULL;
	ip[0] = head;

	for(int i = 1; i < n; i++){
		Node *node = (Node*)malloc(sizeof(Node));
		node->id = i;
		node->prev = ip[i-1];
		node->prev->next = node;
		node->next = NULL;
		ip[i] = node;
	}

	return head;
}

void _remove(Node **head, int x){
	if(ip[x] == *head) *head = (*head)->next;
	if(ip[x]->prev != NULL) ip[x]->prev->next = ip[x]->next;
	if(ip[x]->next != NULL) ip[x]->next->prev = ip[x]->prev;
	free(ip[x]);
	ip[x] = NULL;
}

void moveAonB(Node **head, int a, int b){
	//b->next = a
	if(ip[a] == *head) *head = ip[a]->next;
	if(ip[a]->prev != NULL) ip[a]->prev->next = ip[a]->next;
	if(ip[a]->next != NULL) ip[a]->next->prev = ip[a]->prev;
	
	ip[a]->next = ip[b]->next;
	if(ip[a]->next != NULL) ip[a]->next->prev = ip[a];
	ip[b]->next = ip[a];
	ip[a]->prev = ip[b];
}
void moveAunderB(Node **head, int a, int b){
	//a->next = b;
	if(ip[a] == *head) *head = ip[a]->next;
	if(ip[b] == *head) *head = ip[a];
	if(ip[a]->prev != NULL) ip[a]->prev->next = ip[a]->next;
	if(ip[a]->next != NULL) ip[a]->next->prev = ip[a]->prev;
	
	ip[a]->next = ip[b];
	ip[a]->prev = ip[b]->prev;
	ip[b]->prev = ip[a];
	if(ip[a]->prev != NULL) ip[a]->prev->next = ip[a];	
}

void print(Node* head){
	while(head != NULL){
		printf("%d ", head->id);
		head = head->next;
	}
	printf("\n");
}

int main(){
	int n;
	Node *head;
	scanf("%d", &n);
	head = build(n);

	char cmd[10];
	int a, b;
	while(1){
		scanf("%s", cmd);
		if(cmd[0] == 'e') break;
		else if(cmd[0] == 'm'){
			scanf("%d", &a);
			scanf("%s", cmd);
			scanf("%d", &b);
			if(a >= n || b >= n || ip[a] == NULL || ip[b] == NULL) continue;
			if(cmd[0] == 'o'){
				if(ip[b]->next != ip[a]) moveAonB(&head, a, b);
			}
			else if(cmd[0] == 'u'){
				if(ip[a]->next != ip[b]) moveAunderB(&head, a, b);
			}
		}
		else if(cmd[0] == 'r'){
			scanf("%d", &a);
			if(a < n && ip[a] != NULL)
				_remove(&head, a);
		}
	}

	print(head);
}
