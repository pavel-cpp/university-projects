#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *file;
	file = fopen("/Users/user/pz04/firstfile.txt", "w");
	for(i = 0, i <= 100, i++){
		if(i % 10 = 0)
			fprintf(file, "\n");
		fprintf(file, "123");
	}
	fclose(file);
	return 0;
}