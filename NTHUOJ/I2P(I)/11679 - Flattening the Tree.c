#include<stdio.h>

int n;
int tree[10000];

void lcr(int i)
{
	//printf("i:%d\n", i);
	if(i > n) return;
	lcr(2 * i);
	if(i == n) printf("%d\n", tree[i]);
	else printf("%d ", tree[i]);
	lcr(2 * i + 1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &tree[i]);
	lcr(1);
}


