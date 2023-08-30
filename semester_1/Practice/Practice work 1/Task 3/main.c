#include <stdio.h>

int main(){
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);
    if(n % k == 0){
        printf("n multiple k\n");
    }else{
        printf("n not multiple k\n");
    }
    return 0;
}
