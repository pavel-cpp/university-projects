#include <stdio.h>

int main(){
    int n, k;
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input k: ");
    scanf("%d", &k);
    if(n % k == 0){
        printf("n multiple k\n");
    }else{
        printf("n not multiple k\n");
    }
    return 0;
}
