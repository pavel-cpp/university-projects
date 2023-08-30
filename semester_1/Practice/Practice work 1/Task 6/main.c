#include <stdio.h>

int main(){
    int n, k;
    printf("Enter number: ");
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("even\n");
    }else{
        printf("odd\n");
    }
    return 0;
}
