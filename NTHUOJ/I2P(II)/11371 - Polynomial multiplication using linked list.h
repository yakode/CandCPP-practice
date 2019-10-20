#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include <stdlib.h>
#include <stdio.h>
typedef struct _Node{
	long long data;  //the value of coefficient
	int power; //the value of power
	struct _Node *next;
	struct _Node *prev;
}Node;
//the function which will print the output
void printNode(Node* head){
	while(head != NULL){
		if(head->data != 0){
			printf(" %lld %d", head->data, head->power);
		}
		head = head->next;
	}
}         
//create polynomial linked list
Node* create(){
	Node *head = NULL, *tmp, *pre;
	long long int d;
   	int p;
	while(1){
		scanf("%lld%d", &d, &p);
		if(d == 0 && p == 0) break;
		if(d == 0) continue;

		tmp = (Node*) malloc(sizeof(Node));
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->data = d;
		tmp->power = p;
		if(head == NULL){ head = tmp; pre = head;}
		else{
			pre->next = tmp;
			tmp->prev = pre;
			pre = tmp;
		}
		if(p == 0)break;
	}
	return head;
}
//destroy polynomial linked list
void destroy(Node *node){
	Node *bye;
	while(node != NULL){
		bye = node;
		node = node->next;
		free(bye);
	}
}
//input two polynomial linked list and return the result
Node* multiple(Node* p1, Node* p2){
	Node *ptr2 = p2, *ptr1 = p1;
	Node *p3 = NULL, *tmp;
	while(ptr1 != NULL){
		ptr2 = p2;
		while(ptr2 != NULL){
			long long int d;
			int	p;
			d = ptr1->data * ptr2->data;
			p = ptr1->power + ptr2->power;
			if(p3 == NULL){
				p3 = (Node*)malloc(sizeof(Node));
				p3->next = NULL;
				p3->prev = NULL;
				p3->data = d;
				p3->power = p;
			}else{
				Node *ptr = p3;
				while(ptr->next != NULL && ptr->next->power > p) ptr = ptr->next;
				if(ptr->next != NULL && ptr->next->power == p) ptr->next->data += d;
				else{
					Node *tmp = (Node*)malloc(sizeof(Node));
					tmp->prev = ptr;
					tmp->next = ptr->next;
					tmp->data = d;
					tmp->power = p;
					if(tmp->next != NULL) tmp->next->prev = tmp;
					ptr->next = tmp;
				}
			}

			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return p3;	
}
#endif
