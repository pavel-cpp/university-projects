#include "sosoqe.h" 
#include <stdio.h>
#include <math.h>

int secondMethod(int a, int b, int c){
	if (a == 1){
    	double q = (float)b / 2 / a, p = -c + q * q;
    	if (p >= 0)
            printf("%f\t%f", (sqrt(p) - q), (-sqrt(p) - q));
    	else
    		printf("No roots!");
	}
	else 
		printf("Try another way!");
    return 0;
}