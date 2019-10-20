#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

// changed type of pos
void do_I(Node **head, int pos, unsigned short val){
	if(*head == NULL){
		*head = (Node*)malloc(sizeof(Node));
		(*head)->val = val;
		(*head)->prev = NULL;
		(*head)->next = NULL;
	}else if(pos == 0){
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = val;
		(*head)->prev = node;
		node->next = (*head);
		node->prev = NULL;
		(*head) = node;
	}else{
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = val;
		Node* ptr = *head;
		// have to deal with problem of type
		for(int i = 0; i != pos-1 && ptr->next != NULL; i++) ptr = ptr->next;
		//put node after ptr
		if(ptr->next != NULL) ptr->next->prev = node;
		node->next = ptr->next;
		ptr->next = node;
		node->prev = ptr;
	}	
}
//changed type of poses
void do_E(Node **head,int begin_pos,int end_pos){
	//?if end_pos == last node->next, delete last node or not?
	
	//if begin_pos bigger than length, do nothing
	//if begin_pos or end_pos bigger than length, do nothing
	if(*head == NULL) return;
	if(begin_pos == end_pos) return;

	//find begin_pos first
	Node *ptr = (*head);
	int i;
	for(i = 0; i < begin_pos; i++){
		ptr = ptr->next;
		if(ptr == NULL) return;
		if(ptr->next == NULL){
			if(i != begin_pos-1)return;
			else{
				ptr->prev->next = NULL;
				free(ptr);
				return;
			}
		}
	}
	
	if(ptr == (*head) && ptr->next == NULL){
		(*head) = NULL;
		return;
	}

	Node *end = ptr;
	for( ; i != end_pos; i++){
		end = end->next;
		if(end->next == NULL){
			if(i == end_pos-1){
				//do not delete end
				if(ptr != (*head)){
					ptr->prev->next = end;
					end->prev = ptr->prev;
				}
				else{
					end->prev = NULL;
					(*head) = end;
				}
				free(ptr);
				return;
			}
			else{
				//delete end
				if(ptr != (*head)){
					ptr->prev->next = NULL;
				}
				else{
					(*head) = NULL;
				}
				free(end);
				free(ptr);
				return;
			}
		}
		if(end->prev != ptr) free(end->prev);
	}

	if(ptr != (*head)){
		ptr->prev->next = end;
		end->prev = ptr->prev;
	}else{
		end->prev = NULL;
		(*head) = end;
	}
	free(ptr);
	return;
}
// changed type of pos
void do_P(Node  *head,int pos){
	if(head == NULL) return;
	for(int i = 0; i < pos && head->next != NULL; i++) head = head->next;
	printf("%hu ", head->val);
}
//remove the node whose val equal to what you input
void do_R(Node **head,unsigned short val){
	Node *ptr = (*head);
	while(ptr != NULL){
		if(ptr->val == val){
			if(ptr == *head) *head = ptr->next;
			if(ptr->next != NULL)ptr->next->prev = ptr->prev;
			if(ptr->prev != NULL)ptr->prev->next = ptr->next;
			Node *bye = ptr;
			ptr = ptr->next;
			free(bye);
		}else{
			ptr = ptr->next;
		}
	}
}
void do_S(Node  *head){
	int newline = 0;
	while(head != NULL){
		newline = 1;
		printf("%u ", head->val);
		head = head->next;
	}
	//if(newline) printf("\n");
}


int main(void)
{
	Node *head=NULL;
	int N;
	scanf("%d",&N);
	while(N--)
	{
		char op;
		unsigned short val;
		// i changed type of 55
		int pos,begin_pos,end_pos;
		scanf(" %c",&op);
		switch(op)
		{
		case 'I':
			// i changed type of pos
			scanf("%d %hu",&pos,&val);
			do_I(&head,pos,val);
			break;
		case 'E':
			//changed type 
			scanf("%d %d",&begin_pos,&end_pos);
			do_E(&head,begin_pos,end_pos);
			break;
		case 'P':
			//changed type of pos
			scanf("%d",&pos);
			do_P(head,pos);
			break;
		case 'R':
			scanf("%hu",&val);
			do_R(&head,val);
			break;
		case 'S':
			do_S(head);
			break;
		}
	}
            return 0;
}
