#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void insert(Node **root, int x){
	//printf("insert %d\n", x);
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	if((*root) == NULL){
		(*root) = node;
		return;
	}else{
		Node* ptr = (*root);
		while(ptr != NULL){
			//printf("~%d~", ptr->data);
			if(x > ptr->data){
				//right
				if(ptr->right == NULL){
					ptr->right = node;
					//printf("RIGHT\n");
					return;
				}else{
					ptr = ptr->right;
				}
			}else if(x < ptr->data){
				//left
				if(ptr->left == NULL){
					ptr->left = node;
					//printf("LEFT\n");
					return;
				}else{
					ptr = ptr->left;
				}
			}else{
				return;
			}
		}
	}
}

void create_tree(Node **root, int n){
	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		insert(root, x);
	}
}

void pre(Node *root){
	if(root == NULL) return;
	printf(" %d", root->data);
	pre(root->left);
	pre(root->right);
}
void in(Node *root){
	if(root == NULL) return;
	in(root->left);
	printf(" %d", root->data);
	in(root->right);
}
void post(Node *root){
	if(root == NULL) return;
	post(root->left);
	post(root->right);
	printf(" %d", root->data);
}

void print_tree(Node *root){
	printf("preorder:");
	pre(root);
	printf("\ninorder:");
	in(root);
	printf("\npostorder:");
	post(root);
	printf("\n");
}


void destroyTree(Node *root)
{
  if(root != NULL)
  {
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
  }
}
int main(void)
{
  int n;
  Node *root = NULL;
  scanf("%d",&n);
  create_tree(&root, n);
  print_tree(root);
  destroyTree(root);
  return 0;
}
