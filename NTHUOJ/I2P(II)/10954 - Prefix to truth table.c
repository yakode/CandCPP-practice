#include <stdio.h>
char s[100];
int i = -1;

int operate(int a, int b, int c, int d){
	i++;
	if(s[i] == '&'){
		int op1 = operate(a, b, c, d);
		int op2 = operate(a, b, c, d);
		return op1 && op2;
	}
	else if(s[i] == '|'){
		int op1 = operate(a, b, c, d);
		int op2 = operate(a, b, c, d);
		return op1 || op2;
	}
	else if(s[i] == 'A'){
		return a;
	}
	else if(s[i] == 'B'){
		return b;
	}
	else if(s[i] == 'C'){
		return c;
	}
	else if(s[i] == 'D'){
		return d;
	}

}


int main(){
	scanf("%s", s);
	for(int a = 0; a < 2; a++)
		for(int b = 0; b < 2; b++)
			for(int c = 0; c < 2; c++)
				for(int d = 0; d < 2; d++){
					i = -1;
					printf("%d %d %d %d %d\n", a, b, c, d, operate(a,b,c,d));
				}
	return 0;
}
