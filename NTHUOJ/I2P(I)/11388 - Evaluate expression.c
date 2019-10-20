#include <stdio.h>
#include <string.h>


int main(){
    char input[100];
    int A, B, C, D;
    int log[100];
    scanf("%s",input);
    scanf("%d%d%d%d",&A ,&B ,&C ,&D);
    int len = strlen(input);
    int i;
    for(i=0; i<len; i++){
        if(input[i] == 'A') log[i] = A;
        else if(input[i] == 'B') log[i] = B;
        else if(input[i] == 'C') log[i] = C;
        else if(input[i] == 'D') log[i] = D;
        else if(input[i] == '|') log[i] = 2;
        else if(input[i] == '&') log[i] = 3;
    }
    int tmp;
    int j;
    for(j=len-1; j>=0; j--){
        if(log[j] == 2){
            log[j] = log[j+1] | log[j+2];
            log[j+1] = tmp;
            tmp = log[j];
        }
        else if(log[j] == 3){
            log[j] = log[j+1] & log[j+2];
            log[j+1] = tmp;
            tmp = log[j];
        }
    }
    printf("%d",log[0]);
    return 0;
}

