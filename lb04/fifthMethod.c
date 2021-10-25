//переброска (5)
#include "sosoqe.h" 
#include <stdio.h>
#include <math.h>

void fifthMethod(double a, double b, double c){
	if(a == 1)
		fourthMethod(a, b, c);
	else{
		double yc = a * c, preAns1, preAns2;
		int cycle = 0;
		preAns1 = modifiedFourthMethod(1, b, yc, cycle);
		cycle++;
		preAns2 = modifiedFourthMethod(1, b, yc, cycle);
		printf("%f\t%f", (preAns2 / a), (preAns1 / a));
	}
}