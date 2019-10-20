#include <stdio.h>
#include <ctype.h>
char c;

double calculate()
{
	double op1, op2;
	double ans;
	c = getchar();
	//if(c == '=')
	if(c == '+'){
		op1 = calculate();
		op2 = calculate();
		ans = op1 + op2;
	}
	else if(c == '-'){
		op1 = calculate();
		op2 = calculate();
		ans = op1 - op2;
	}
	else if(c == '*'){
		op1 = calculate();
		op2 = calculate();
		ans = op1 * op2;
	}
	else if(c == '/'){
		op1 = calculate();
		op2 = calculate();
		ans = op1 / op2;
	}
	else if(isdigit(c)){
		ans = c - '0';
	}
	return ans;
}

int main()
{
	printf("%.3lf", calculate());
	return 0;
}

