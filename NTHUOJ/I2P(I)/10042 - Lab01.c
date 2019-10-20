#include <stdio.h>

int main(){
    int A, B;
    scanf("%d%d",&A ,&B);
    int C = (B+9*A) / 18;
    int ans = (A-C)*10 + C;
    printf("%d",ans);
}
