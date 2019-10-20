#include <stdio.h>
#include <string.h>
int main(){
    char input[10];
    scanf("%s",input);
    for(int i=0; i<3; i++){
        printf("%c",input[i]+16);
    }
    return 0;
}

