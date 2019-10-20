#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
	if(inorder_start > inorder_end) return NULL;
	static int id = 0;
	Node *root = (Node*)malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	root->data = preorder[id++];

	if(inorder_start == inorder_end){
		return root;
	}else{
		int i = inorder_start;
		while(inorder[i] != root->data) i++;
		root->left = buildTree(inorder, preorder, inorder_start, i-1);
		root->right = buildTree(inorder, preorder, i+1, inorder_end);	
	}
	return root;
}

void showPostorder(Node* root){
	if(root == NULL) return;
	showPostorder(root->left);
	showPostorder(root->right);
	printf("%d ", root->data);
}

void freeTree(Node *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void){

    int i,n;
    int *inorder,*preorder;
    scanf("%d",&n); // n : the size of binary tree
    /*------------Parse the input----------------*/
    inorder = (int *) malloc(n * sizeof(int));
    preorder = (int *) malloc(n * sizeof(int));
    for(i=0; i<n; i++) scanf("%d", &inorder[i]);
    for(i=0; i<n; i++) scanf("%d", &preorder[i]);
    /*------------Build the binary tree----------*/
    Node *root = buildTree(inorder, preorder,0,n-1);
    /*------------Print out the tree ------------*/
    showPostorder(root);
    freeTree(root);
    free(inorder);
    free(preorder);
    return 0;
}

