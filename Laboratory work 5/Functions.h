#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10

void clear(){
#ifdef WIN_32
    system("clear");
#else
    system("cls");
#endif
}

void fclear(){
    FILE *dataout = fopen("output.txt", "w+");
    fprintf(dataout, "");
    fclose(dataout);
}

void algorithmX(int a[n], int b[n]){
    float x[n];
    for (int i = 0; i < n; i++) {
        if(a[i] <= b[i]) x[i] = (float)a[i] / 2;
        else x[i] = (float)b[i] / 2;
    }
    printf("\nМассив [x]: ");
    for (int i = 0; i < n; ++i) printf("%g ", x[i]);
    fclear();
    FILE *dataout = fopen("output.txt", "a");
    fprintf(dataout, "Массив [X]: ");
    for (int i = 0; i < n; ++i) fprintf(dataout, "%g ", x[i]);
    fclose(dataout);
    return;
}

void algorithmY(int b[n], int c[n]){
    float y[n];
    for (int i = 0; i < n; i++) {
        if(b[i] <= c[i]) y[i] = (float)b[i] / 2;
        else y[i] = (float)c[i] / 2;
    }
    printf("\nМассив [Y]: ");
    for (int i = 0; i < n; ++i) printf("%g ", y[i]);
    FILE *dataout = fopen("output.txt", "a");
    fprintf(dataout, "\nМассив [Y]: ");
    for (int i = 0; i < n; ++i) fprintf(dataout, "%g ", y[i]);
    fclose(dataout);
    return;
}

int algorithm2(int mass[n]){
    int length, buff = 11, ans = 0;
    for (int i = n - 1; i >= 0; i--)
        if (mass[i] == 0) {
            length = i;
            break;
        }
    for (int i = 0; i < n; i++)
        if (mass[i] == 0) {
            buff = i;
            break;
        }
    for (; buff <= length; buff++) ans+=mass[buff];
    return ans;
}

int algorithm(int mass[n]){
	int hook = -1;
	for (int i = 1; i < n; i++){
		if(hook != -1 && mass[i] % 2 == 0 && mass[i] != 0) mass[hook]*=mass[i];
		if(hook == -1 && mass[i] % 2 == 0 && mass[i] != 0) hook = i;
	}
	if(hook != -1) return mass[hook];
	return -1;
}

void output(int answer){
	printf("\n   Ответ: %d\n   Ответ сохранен в файл output.txt", answer);
	FILE *dataout = fopen("output.txt", "w+");
	fprintf(dataout, "Ответ: %d", answer);
	fclose(dataout);
}

void preoutputForC(int a[n], int b[n], int c[n]){
    clear();
    int i;
    printf("Массив [А]: ");
    for (i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\nМассив [B]: ");
    for (i = 0; i < n; ++i) printf("%d ", b[i]);
    printf("\nМассив [C]: ");
    for (i = 0; i < n; ++i) printf("%d ", c[i]);
    return;
}

void preoutput(int m[]){
    clear();
	for (int i = 0; i < n; ++i) printf("%d ", m[i]);
	return;
}

void firstMod(int a[n]){
    clear();
    printf("\n   Заполните массив [b]: \n\n");
    int b[n];
    for (int i = 0; i < n; i++){
        printf("    Элемент[%i]: ", i + 1);
        scanf("%d", &b[i]);
    }
    clear();
    printf("\n   Заполните массив [c]: \n\n");
    int c[n];
    for (int i = 0; i < n; i++){
        printf("    Элемент[%i]: ", i + 1);
        scanf("%d", &c[i]);
    }
    preoutputForC(a, b, c);
    printf("\n\nОтвет: ");
    algorithmX(a, b);
    algorithmY(b, c);
    return;
}

void secondMod(int a[n]){
    FILE *data = fopen("data.txt", "r");
    int b[n], c[n];
    for (int i = 0; i < n; i++) fscanf(data, "%i", &a[i]);
    for (int i = 0; i < n; i++) fscanf(data, "%i", &b[i]);
    for (int i = 0; i < n; i++) fscanf(data, "%i", &c[i]);
    fclose(data);
    preoutputForC(a, b, c);
    printf("\n\nОтвет: ");
    algorithmX(a, b);
    algorithmY(b, c);
    return;
}

void thirdMod(int a[n]){
    srand(time(NULL));
    int b[n], c[n];
    for (int i = 0; i < n; i++) b[i] = -100+rand()%(100+100+1);
    for (int i = 0; i < n; i++) c[i] = -100+rand()%(100+100+1);
    preoutputForC(a, b, c);
    printf("\n\nОтвет: ");
    algorithmX(a, b);
    algorithmY(b, c);
    return;
}

void fourthMod(int a[n]){
    int b[n] = {2, 0, -10, 65, 3, 7, 3, 88, 0, -1};
    int c[n] = {3, 4, -3, 54, 12, 35, -21, 10, -3, -2};
    preoutputForC(a, b, c);
    printf("\n\nОтвет: ");
    algorithmX(a, b);
    algorithmY(b, c);
    return;
}

void methods(int mass[n], int cases){
    int mcases;
    clear();
    printf("Выберите алгоритм решения:\n  1) Вычислить произведение элементов массива с четными номерами;\n  2) Вычислить сумму элементов массива, расположенных между первым и последним нулевыми элементами\n  3) Вычислить Задание 03 в табл. «Варианты заданий»\n");
    scanf("%d", &mcases);
    switch(mcases){
        case 1:
            printf("Массив: ");
            preoutput(mass);
            output(algorithm(mass));
            break;
        case 2:
            printf("Массив: ");
            preoutput(mass);
            output(algorithm2(mass));
            break;
        case 3:
                switch(cases){
                    case 1:
                        firstMod(mass);
                        break;
                    case 2:
                        secondMod(mass);
                        break;
                    case 3:
                        thirdMod(mass);
                        break;
                    case 4:
                        fourthMod(mass);
                        break;
                }

            break;
    }
}

void first(int cases){
    clear();
    printf("\n   Заполните массив: \n\n");
	int mass[n];
	for (int i = 0; i < n; i++){
        printf("    Элемент[%i]: ", i + 1);
		scanf("%d", &mass[i]);
	}
    methods(mass, cases);
	return;
}

void second(int cases){
	FILE *data = fopen("data.txt", "r");
	int mass[n];
	for (int i = 0; i < n; i++) fscanf(data, "%i", &mass[i]);
	fclose(data);
    methods(mass, cases);
	return;
}

void third(int cases){
	srand(time(NULL));
	int mass[n];
	for (int i = 0; i < n; i++) mass[i] = -100+rand()%(100+100+1);
    methods(mass, cases);
    return;
}

void fourth(int cases){
	int mass[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    methods(mass, cases);
	return;
}