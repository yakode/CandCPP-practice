#include <stdio.h>
#include <string.h>
char s[100], t[100];
int len_s, len_t;
int count;

void substring(int si, int ti){
	if(ti == len_t) count ++;
	else if(si >= len_s) return;
	else if(s[si] == t[ti]){
		substring(si + 1, ti + 1);
		substring(si + 1, ti);
	}
	else
		substring(si + 1, ti);
}

int main(){
	while(scanf("%s", s) != EOF){
		scanf("%s", t);
		len_s = strlen(s);
		len_t = strlen(t);
		count = 0;
		substring(0, 0);
		printf("%d\n", count);
	}
	return 0;
}
