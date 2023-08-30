#include "../../headers/sosoqe.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int firstMethod(int a, int b, int c){
    if(a == 1)
        for(int ans1=-100; ans1 <= abs(c); ans1++){
            int ans2 = b - ans1;
            if(ans2 != 0 && (float)c/ans2 == ans1){
                printf("%f\t%f", (float)-ans1, (float)-ans2);
                return 0;
            }
        }
    return -1;
}