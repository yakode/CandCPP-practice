#include <stdio.h>
#include <stdlib.h>

int main(){
	int M, N, P;
	int x = 0, y = 1, i = 0, done = 0;
	scanf("%d%d%d", &M, &N, &P);

	if(P < N){
		x += P;
		done = 1;	
	}
	else{
		x += N;
		i += N;
	}

	for(int j = 1; !done && i < P; j++){
		if(i + (M-j) < P){
			y += (M-j);
			i += (M-j);
		}
		else{
			y += (P-i);
			done = 1;
			break;
		}

		if(i + (N-j) < P){
			x -= (N-j);
			i += (N-j);
		}
		else{
			x -= (P-i);
			done = 1;
			break;
		}
		
		j++;
		if(i + (M-j) < P){
			y -= (M-j);
			i += (M-j);
		}
		else{
			y -= (P-i);
			done = 1;
			break;
		}
		if(i + (N-j) < P){
			x += (N-j);
			i += (N-j);
		}
		else{
			x += (P-i);
			done = 1;
			break;
		}
	}
	printf("%d %d\n", y, x);
	return 0;
}
