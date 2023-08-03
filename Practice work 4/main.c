#include <stdio.h>

int main(){
	FILE *input = fopen("input", "r");
	FILE *output;
	char type;
	puts("Print or copy (p/c) ?");
	scanf("%c", &type);
	if(type == 'p' || type == 'P'){
		char str;
		while(!feof(input)){
			str = fgetc(input);
			printf("%c", str);
		}
	}
	else if(type == 'C' || type == 'c'){
		output = fopen("new_file", "w+");
		char str;
		while(!feof(input)){
			str = fgetc(input);
			fprintf(output, "%c", str);
		}
	}
	else{
		puts("There's not this choice.");
	}
	return 0;
}