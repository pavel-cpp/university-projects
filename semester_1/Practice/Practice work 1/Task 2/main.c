#include <stdio.h>
#include <math.h>

int main(){
    int x;
    printf("Input x: ");
    scanf("%d", &x);
    if(x > 0){
        printf("y = %d", 2 * x - 10);
    }else if(x == 0){
        printf("y = 0");
    }else{
        printf("y = %d", 2 * abs(x) - 1);
    }
    return 0;
}
