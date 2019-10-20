#include <stdio.h>

int main(){
	int input;
	char flag = 'a';
	scanf("%d",&input);
	int min = input % 100;
	int hr = input / 100;
	if(hr >= 12 && hr != 0) flag = 'p';
	while(hr >= 12) hr -= 12;
	printf("%02d:%02d %c.m.",hr ,min ,flag);
	return 0;
} 
