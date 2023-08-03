#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main(){
    system("clear");
	int cases;
	printf("Задача №03 Ремденок Павел Александрович, ИКПИ-15\nВыберите ввод исходных данных: \n 1) с экрана; \n 2) из файла; \n 3) рандомные значения; \n 4) Из тела программы; \n Ввод: ");
	scanf("%d", &cases);
	switch(cases) {
        case 27:
            return 0;
        case 1:
            first(cases);
            break;
        case 2:
            second(cases);
            break;
        case 3:
            third(cases);
            break;
        case 4:
            fourth(cases);
            break;
    }
    return 0;
}