#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	int data;
	struct _node *left, *right;
}Node;

void insert(Node **root, int x){
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	
	if(*root == NULL){
		*root = node;
	} else{
		Node *ptr = *root;
		while(ptr != NULL){
			if(x > ptr->data){
				if(ptr->right == NULL){
					ptr->right = node;
					break;
				}
				ptr = ptr->right;
			}else if(x < ptr->data){
				if(ptr->left == NULL){
					ptr->left = node;
					break;
				}
				ptr = ptr->left;
			}else{
				break;
			}
		}
	}
}
void P(Node* root, int N){
	if(root == NULL)
		return;
	P(root->left, N);
	printf("%d ", root->data);
	P(root->right, N);
}

int GetMax(Node* root){
	if(root == NULL) return 0;
	return (GetMax(root->left) > GetMax(root->right))? GetMax(root->left)+1:GetMax(root->right)+1;
}

int SumLevel(Node* root, int level_now, int level_goal){
	if(root == NULL) return 0;
	if(level_now == level_goal) return root->data;
	return SumLevel(root->left, level_now+1, level_goal) + SumLevel(root->right, level_now+1, level_goal);
}

int counting(Node* root, int level_now, int level_goal){
	if(root == NULL) return 0;
	if(level_now == level_goal) return 1;
	return counting(root->left, level_now+1, level_goal) + counting(root->right, level_now+1, level_goal);
}

int main(){
	int N, x;
	scanf("%d", &N);
	Node *root = NULL;
	for(int i = 0; i < N; i++){
		scanf("%d", &x);
		insert(&root, x);
	}
	
	int M;
	char cmd[10];
	scanf("%d", &M);
	while(M--){
		scanf("%s", cmd);
		if(cmd[0] == 'P'){
			if(root == NULL) printf("NULL\n");
			else{
				P(root, N);
				printf("\n");
			}
		}else if(cmd[0] == 'G'){
			printf("%d\n", GetMax(root));
		}else if(cmd[0] == 'S'){
			scanf("%d", &x);
			if(x > GetMax(root) || x == 0)
				printf("0\n");
			else
				printf("%d\n", SumLevel(root, 1, x));
		}else if(cmd[0] == 'A'){
			scanf("%d", &x);
			if(x > GetMax(root) || x == 0)
				printf("0\n");
			else
				printf("%.3lf\n", (double)SumLevel(root, 1, x)/counting(root, 1, x));
		}
	}
	return 0;
}
