//Дискриминант (3)
#include "sosoqe.h" 
#include <stdio.h>
#include <math.h>

int thirdMethod(int a, int b, int c)
{
    float D = sqrt(pow(b, 2) - 4 * a * c), ans1 = ((-1) * b + D) / (2 * a), ans2 = ((-1) * b - D) / (2 * a);
    if(D>=0){
    printf("%f\t%f", ans1, ans2);    
    }
    else{
        printf("Error");
        return -1;
    }
    return -1; 
}