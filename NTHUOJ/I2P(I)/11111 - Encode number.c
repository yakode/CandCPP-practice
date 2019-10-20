#include <stdio.h>

int main(){
    int input;
    scanf("%d",&input);
    int s1 = input/100;
    int s2 = input/10%10;
    int s3 = input%10;
    printf("%c%c%c",s1+64 ,s2+64 ,s3+64);
    return 0;
}

