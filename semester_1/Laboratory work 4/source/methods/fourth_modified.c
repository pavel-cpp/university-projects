// вспомогательная функция
#include "../../headers/sosoqe.h"
#include <stdio.h>
#include <math.h>

double modifiedFourthMethod(double a, double b, double c, int cycle){
    double ans[2];
    for(ans[0]=-100; ans[0] <= 100; ans[0]+=0.01)
        for(ans[1]=-100; ans[1] <= 100; ans[1]+=0.01)
            if(fabs(ans[0] + ans[1] + b / a) <= 0.0001 && fabs(ans[0] * ans[1] - c / a) <= 0.0001){
            if(cycle == 0)
                return ans[0];
            else
                return ans[1];
            }
    return 0;   
}