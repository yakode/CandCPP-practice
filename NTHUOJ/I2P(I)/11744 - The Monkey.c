#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	char word;
	struct _Node *left;
	struct _Node *right;
} Node;

Node* head = NULL;
Node* cursor = NULL;

void shift_right(){
	if(cursor -> right != NULL)
		cursor = cursor -> right;
}

void shift_left(){
	if(cursor -> left != NULL)
		cursor = cursor -> left;
}

void delete(){
	if(cursor -> right != NULL){
		Node* tmp = cursor -> right;
		cursor -> right = tmp -> right;
		if(tmp -> right != NULL)
			tmp -> right -> left = cursor;
		free(tmp);
	}
}

void type(char new){
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp -> word = new;
	tmp -> right = NULL;
	if(cursor -> right != NULL){
		cursor -> right -> left = tmp;
		tmp -> right = cursor -> right;
	}
	tmp -> left = cursor;
	cursor -> right = tmp;
	cursor = tmp;
}


void show(){
	while(head -> right != NULL){
		head = head -> right;
		printf("%c", head -> word);
		free(head -> left);
	}
	free(head);
	printf("\n");
}

int main(){
	head = (Node*) malloc(sizeof(Node));
	head -> word = '0';
	head -> left = NULL;
	head -> right = NULL;
	cursor = head;

	char cmd;
	while(1){
		cmd = getchar();
		if(cmd == '\n' || cmd == EOF)
			break;
		else if(cmd == '>')
			shift_right();
		else if(cmd == '<')
			shift_left();
		else if(cmd == 'D')
			delete();
		else
			type(cmd);
	}

	show();
	return 0;
}

