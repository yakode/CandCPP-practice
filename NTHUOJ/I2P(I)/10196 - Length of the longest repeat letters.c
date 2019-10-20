#include <stdio.h>
#include <ctype.h>

int main(){
	char pre = 'a', sth;
	unsigned long long int count = 0, max = 0;
	while((sth=getchar()) != '\n'){
		if(count == 0) count = 1;
		sth = toupper(sth);
		if(pre != sth){
			if(count > max) max = count;
			count = 1;
			pre = sth;
		}
		else{
			count ++;
		}
	}
	if(count > max) max = count;
	printf("%llu\n", max);
	return 0;
}
