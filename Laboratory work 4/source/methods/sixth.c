#include "../../headers/sosoqe.h"
#include <stdio.h>
#include <math.h>

void sixthMethod(int a, int b, int c){
	if(a + b + c == 0)
		printf("%f\t%f\n", 1.0, (float)c/a);
	if(b % 2 == 0)
		printf("%f\t%f\n", (((-b / 2) + sqrt(pow((b / 2), 2) - a * c))/a), (((-b / 2) - sqrt(pow((b / 2), 2) - a * c))/a));
	if(a == 1)
		printf("%f\t%f", ((-b + sqrt(pow(b, 2) - 4 * c))/2), ((-b - sqrt(pow(b, 2) - 4 * c))/2));
}