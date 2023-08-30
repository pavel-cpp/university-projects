#include <stdio.h>

int main(){
    int height, weight;
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter real height: ");
    scanf("%d", &weight);
    if(height - 100 == weight){
        printf("Everything is fine\n");
    }else if(height - 100 == weight){
        printf("you need to lose weight\n");
    }else{
        printf("You need to get fat\n");
    }
    return 0;
}
