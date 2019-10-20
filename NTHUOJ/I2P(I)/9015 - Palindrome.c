#include <stdio.h>
#include <string.h>

int main(){
	char text[100000];
	while(scanf("%s", text) != EOF){
		int len = strlen(text);
		int half = len / 2;
		int jud = 1;
		for(int i = 0; i < half; i++){
			if(text[i] != text[len-i-1]){
				jud = 0;
				break;
			}
		}
		if(jud) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
