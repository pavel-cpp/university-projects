//Виета (4)
#include "sosoqe.h" 
#include <stdio.h>
#include <math.h>

double fourthMethod(double a, double b, double c){
    double ans[2];
    for(ans[0]=-100; ans[0] <= 100; ans[0]+=0.01)
        for(ans[1]=-100; ans[1] <= 100; ans[1]+=0.01)
            if(fabs(ans[0] + ans[1] + b / a) <= 0.0001 && fabs(ans[0] * ans[1] - c / a) <= 0.0001){
            printf("%f\t%f", ans[1], ans[0]);
            return 0;
            }
    return 0;           
}