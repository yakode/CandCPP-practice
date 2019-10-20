#include <stdio.h>
#include <string.h>
char s[1000000];
int checked[2000+5][2000+5]; // 0 : not yet, 1 : yes, -1 : no 
int done[2000+5][2000+5];
int count;

int hui(int left, int right){
	if(left > right) return 0;
	if(checked[left][right] == 1) return 1;
	if(checked[left][right] == -1) return 0;
	if(left + 1 == right){
		if(s[left] == s[right]){
			checked[left][right] = 1;
			return 1;
		}
		else{
			checked[left][right] = -1;
			return 0;
		}
	}
	if(s[left] == s[right] && hui(left+1, right-1) == 1){
		checked[left][right] = 1;
		return 1;
	}
	checked[left][right] = -1;
	return 0;
}

void sub(int left, int right){
	if(left == right) return;
	if(done[left][right] == 1) return;
	done[left][right] = 1;
	//printf("%d~%d : %d\n", left, right, count);
	if(hui(left, right)) count ++;
	sub(left + 1, right);
	sub(left, right - 1);
}

void initial(int len){
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			if(i == j) checked[i][j] = 1;
			else checked[i][j] = 0;
			done[i][j] = 0;
		}
	}
	count = 0;
}

int main(){
	while(scanf("%s", s) != EOF){
		int len = strlen(s);
		initial(len);
		sub(0,len-1);
		printf("%d\n", count);
	}
	return 0;
} 
