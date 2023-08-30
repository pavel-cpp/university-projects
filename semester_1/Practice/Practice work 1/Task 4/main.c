#include <stdio.h>

const float SMALL_DISCOUNT = 0.97;
const float BIG_DISCOUNT = 0.95;
const float NO_DISCOUNT = 1;

int main(){
    printf("Calculating the cost of a purchase with a discount\n");
    printf("Enter the purchase amount and press <Enter>\n");
    float cost, discount = NO_DISCOUNT;
    scanf("%f", &cost);
    if(cost > 1000){
        discount = BIG_DISCOUNT;
        printf("You get a 5%% discount\n");
    }else if(cost > 500){
        discount = SMALL_DISCOUNT;
        printf("You get a 3%% discount\n");
    }
    printf("Amount including discount: %g rub.", cost * discount);
    return 0;
}
