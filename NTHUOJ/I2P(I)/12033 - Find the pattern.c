#include <stdio.h>
#include <string.h>

int main(){
	int lp, ls;
	char p[100000], s[100000];
	int done = 0;
	scanf("%s%d%s%d", &p, &lp, &s, &ls);
	for(int i = 0; i < lp - ls + 1; i++){
		if(done == 1) break;
		if(p[i] == s[0]){
			int tmp = 1;
			for(int j = 0; j < ls; j++){
				if(p[i+j] != s[j]){
					tmp = 0;
					break;
				}
			}
			if(tmp == 1) done = 1;
		}
	}
	if(done == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
