#include <stdio.h>
#include <string.h>
char s[100];
char ans[100];
int used[100];
int len;

void permutation(int n){
	if(n == len){
		for(int i = 0; i < n; i++){
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	for(int i = 0; i < len; i++){
		if(i < (len-1) && used[i] == 0 && s[i] == s[i+1] && used[i+1] == 1) return;
		if(used[i] == 0){
			used[i] = 1;
			ans[n] = s[i];
			permutation( n+1 );
			used[i] = 0;
		}
	}
}

void sort(){
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len - i - 1; j++){
			if(s[j] > s[j+1]){
				char tmp = s[j];
				s[j] = s[j+1];
				s[j+1] = tmp;
			}
		}
	}
}

int main(){
	scanf("%s", s);
	len = strlen(s);
	sort();
	permutation(0);
	return 0;
}
