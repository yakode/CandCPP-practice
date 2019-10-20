#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int bin[1000] = {};
    int i;
    for(i=0; N>0; i++){
        bin[i] = N % 2;
        N /= 2;
    }
    int base = 1;
    int ans = 0;
    for(i=7 ; i>=0; i--){
        ans += bin[i] * base;
        base *= 2;
    }
    printf("%d\n",ans);
    return 0;
}

