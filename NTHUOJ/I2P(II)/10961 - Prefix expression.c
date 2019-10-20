#include <stdio.h>
#include <ctype.h>

int calculate(){
	int op1, op2;
	char c;
	c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '0') return 0;
	if(c == '+'){
		op1 = calculate();
		op2 = calculate();
		return op1 + op2;
	}else if(c == '-'){
		op1 = calculate();
		op2 = calculate();
		return op1 - op2;
	}else if(isdigit(c)){
		ungetc(c, stdin);
		int num;
		scanf("%d", &num);
		return num;
	}
}

int main(){
	printf("%d", calculate());
	return 0;
}
