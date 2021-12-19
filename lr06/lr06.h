#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>


int scale(int max, float check){
    int scale = 0;
    if(max <= 0) scale++;
    while(max != 0){
        max /= 10;
        scale++;
    }
    if(check > -1 && check < 0) return 2;
    return scale;
}

int maxFromArray(int x, int y, float **array){
    float max = 0, checkO = 0, checkH = 0;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++){
            if(fabs(array[i][j]) > fabs(max)) max = array[i][j];
            if(array [i][j] > -1000 && array[i][j] < -100) checkH = 4;
            if(array[i][j] < 0 && array[i][j] > -1) checkO = 2;
        }
    if(scale((int)max, 0) <= checkO) return 10;
    if(scale((int)max, 0) <= checkH) return 1000;
    return (int)max;
}

void dynamicLines(int scale, int x){
    char one[8] = "+------", two[9] = "+-------", three[10] = "+--------", four[11] = "+---------";
    switch(scale){
        case 1:
            printf("                                        ");
            for (int j = 0; j < x; j++) printf("%7s", one);
            break;
        case 2:
            printf("                                        ");
            for (int j = 0; j < x; j++) printf("%8s", two);
            break;
        case 3:
            printf("                                        ");
            for (int j = 0; j < x; j++) printf("%9s", three);
            break;
        case 4:
            printf("                                        ");
            for (int j = 0; j < x; j++) printf("%10s", four);
            break;
    }
    printf("+\n");
}

void graphicCore(int x, int y, int scaleOf, float **array, int null){
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                        ");
    for (int i = 0; i < x; i++) {
        switch(scaleOf - 1){
            case 0:
                printf("   %d   ", i);
                break;
            case 1:
                printf("    %d   ", i);
                break;
            case 2:
                printf("    %d    ", i);
                break;
            case 3:
                printf("     %d    ", i);
                break;
        }
    }
    printf("\n");
    dynamicLines(scaleOf, x);
    for (int i = 0; i < y; i++){
        printf("                                      %d ", i);
        for (int j = 0; j < x; j++) {
            if(array[i][j] == 0 && null == 1)
                switch(scaleOf){
                    case 1:
                        printf("|      ");
                        break;
                    case 2:
                        printf("|       ");
                        break;
                    case 3:
                        printf("|        ");
                        break;
                    case 4:
                        printf("|         ");
                        break;
                    default:
                        printf("|     ");
                }
            else
                switch(scaleOf - (scale((int)array[i][j], array[i][j]))){
                    case 0:
                        printf("| %2.2f ", array[i][j]);
                        break;
                    case 1:
                        printf("|  %2.2f ", array[i][j]);
                        break;
                    case 2:
                        printf("|   %2.2f ", array[i][j]);
                        break;
                    case 3:
                        printf("|    %2.2f ", array[i][j]);
                        break;
                    default:
                        printf("|%2.2f ", array[i][j]);
                }

        }
        printf("|\n");
        dynamicLines(scaleOf, x);
    }
}

int Checker(){
    int a;
    if(scanf("%d", &a) != 1){
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                             Критическая ошибка! Программа принимает только числа!\n                                             Программа перезапуститься через несколько секунд...\n");
        usleep(4000000);
        system("./p");
        _exit(EXIT_SUCCESS);
    }
    if (a < 1 || a > 4){
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                              Не верно выбран номер, попробуй еще раз!\n");
        usleep(2000000);
        return -1;
    }
    return a;
}

float programm(int i, int j){
    float arrayInProgramm[10][10] = {{-110.45, -56.44, -289.96, 240.76, -75.64, -126.23, -258.78, -273.69, 42.84, -423.04}, {269.31, -29.45, -19.73, 377.64, -395.41, 79.53, -66.61, 284.20, -100.57, 316.72}, {-136.92, 165.72, -106.48, 228.58, -146.32, -366.22, -238.37, 132.06, 343.79, -168.03}, {385.53, 3.44, 259.84, -340.10, 29.92, -423.89, 135.77, 256.32, -360.39, 202.46}, {49.59, 36.84, 109.63, -341.41, 481.61, 198.62, 33.50, -432.90, -89.42, -383.32}, {297.85, -157.32, -353.61, -253.49, 147.87, 66.42, -107.42, 73.50, -394.02, -26.23}, {424.58, -333.53, -341.63, -78.40, 371.96, -79.07, 260.55, 69.35, -164.51, 234.31}, {-339.37, -106.88, -436.60, -112.93, 302.38, 85.69, 418.46, 9.66, -429.08, -25.25}, {-311.94, 496.70, -464.39, -483.41, -412.85, -171.67, -311.09, -386.92, 393.68, 420.82}, {154.89, -331.43, -468.46, -214.23, 408.25, 254.90, 186.24, 322.34, 432.04, 216.28}};
    return arrayInProgramm[i][j];
}

float screen(int i, int j){
    float cell;
    printf("\n\n                                             Введите значение в ячейку[%d][%d]: ", i, j);
    if(scanf("%f", &cell) != 1){
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                             Критическая ошибка! Программа принимает только числа!\n                                             Программа перезапуститься через несколько секунд...\n");
        usleep(4000000);
        system("./p");
        _exit(EXIT_SUCCESS);
    }
    return cell;
}

void fclear(){
    FILE *output = fopen("dataoutput.txt", "w");
    fprintf(output, "");
    fclose(output);
}

float file(int i, int j){
    FILE *input = fopen("datainput.txt", "r");
    float arrayForRead[10][10];
    for (int k = 0; k < 10; k++)
        for (int l = 0; l < 10; l++)
            fscanf(input, "%f", &arrayForRead[k][l]);
    fclose(input);
    return arrayForRead[i][j];
}

float checkerToTen(){
    float a;
    if(scanf("%f", &a) != 1){
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                             Критическая ошибка! Программа принимает только числа!\n                                             Программа перезапуститься через несколько секунд...\n");
        usleep(4000000);
        system("./p");
        _exit(EXIT_SUCCESS);
    }
    if(a > 10 || a <= 0){
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                             Размер массива не должен превышать 10!\n");
        usleep(2000000);
        system("clear");
        return -1;
    }
    return a;
}

void first(int x, int y, float **array){
    float *min = malloc(y * sizeof(float));
    for (int i = 0; i < y; ++i) min[i] = 1001;
    for (int i = 0; i < y; i++){
        int ox = -1;
        for (int j = 0; j < x; j++){
            if(array[i][j] > 0)
                if(array[i][j] <= min[i]){
                    min[i] = array[i][j];
                    ox = j;
                }
        }
        for (int j = 0; j < x; ++j){
            if(j != ox || ox == -1) array[i][j] = 0;
            system("clear");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
            usleep(30000);
        }
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
    fclear();
    FILE *output = fopen("dataoutput.txt", "a");
    printf("\n\n                            Минимальные элеманты: ");
    fprintf(output, "Минимальные элеманты: ");
    for (int i = 0; i < y; ++i){
        if(min[i] != 1001){
            printf("%2.2f | ", min[i]);
            fprintf(output, "%2.2f | ", min[i]);
        }
        else{
            printf("NAN | ");
            fprintf(output, "NAN | ");
        }
    }
    fclose(output);
    free(min);
}

void second(int x, int y, float **array){
    int numOfMin, numOfMax;
    float min = 1001, max = -1000;
    int j = x - 1;
    for (int i = 0; i < y; i++){
        for (int k = x - 1; k >= 0; k--) {
            if(j != k)array[i][k] = 0;
            graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
            usleep(10000);
        }
        j--;
    }
    for (int i = 0; i < y; i++)
        for (int k = 0; k < x; k++) {
            if(array[i][k] <= min){
                min = array[i][k];
                numOfMin = i;
            }
            if(array[i][k] >= max){
                max = array[i][k];
                numOfMax = i;
            }
        }
    fclear();
    FILE *output = fopen("dataoutput.txt", "a");
    printf("\n\n                     Минимальный: %2.2f (Номер: %d), Максимальный: %2.2f (Номер: %d) | Сумма номеров: %d", min, numOfMin, max, numOfMax, (numOfMin + numOfMax));
    fprintf(output, "Минимальный: %2.2f (Номер: %d), Максимальный: %2.2f (Номер: %d) | Сумма номеров: %d", min, numOfMin, max, numOfMax, (numOfMin + numOfMax));
    fclose(output);
}

int cmp (const void * a, const void * b){
    float x = *(float*)a;
    float y = *(float*)b;
    int i;
    if(x < y) i = -1;
    if(x == y) i = 0;
    if(x > y) i = 1;
    return i;
}

void third(int x, int y, float **array){
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++){
            if(j != 0) array[i][j] = 0;
            graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
            usleep(10000);
        }
    float *buff = malloc(y * sizeof(float *));
    for (int i = 0; i < y; i++) buff[i] = array[i][0];
    qsort(buff, y, sizeof(float), cmp);
    for (int i = 0; i < y; i++){
        array[i][0] = buff[i];
        graphicCore(1, y, scale(maxFromArray(x, y, array), 0), array, 1);
        usleep(30000);
    }
    free(buff);
    graphicCore(1, y, scale(maxFromArray(x, y, array), 0), array, 1);
    fclear();
    FILE *output = fopen("dataoutput.txt", "a");
    printf("\n\n\n    Первый столбец в порядке возрастания: ");
    fprintf(output, "Первый столбец в порядке возрастания: ");
    for (int i = 0; i < y; i++) {
        printf("%2.2f | ", array[i][0]);
        fprintf(output, "%2.2f | ", array[i][0]);
    }
    fclose(output);
}

void fourth(int x, int y, float **array){
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++){
            if(j != i) array[i][j] = 0;
            graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
            usleep(10000);
        }
    float *buff = malloc(y * sizeof(float *));
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            buff[i] = array[i][i];
    qsort(buff, y, sizeof(float), cmp);
    int j = y - 1;
    for (int i = 0; i < y; i++){
        array[i][i] = buff[j];
        graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
        usleep(100000);
        j--;
    }
    graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
    fclear();
    FILE *output = fopen("dataoutput.txt", "a");
    printf("\n\n\n    Главная диагональ в  порядке убывания: ");
    fprintf(output, "Главная диагональ в  порядке убывания: ");
    for (int i = y - 1; i >= 0; i--){
        printf("%2.2f | ", buff[i]);
        fprintf(output, "%2.2f | ", buff[i]);
    }
    fclose(output);
    free(buff);
}

void getch(){
    char ch;
    printf("\n\n                                              Для продолжения нажмите Enter;\n");
    scanf("%c", &ch);
    scanf("%c", &ch);
}

void processor(int numOfMethod, int x, int y, float **array){
    char ch;
    switch (numOfMethod) {
        case 1:
            first(x, y, array);
            break;
        case 2:
            second(x, y, array);
            break;
        case 3:
            third(x, y, array);
            break;
        case 4:
            fourth(x, y, array);
            break;
    }
    printf("\n\n                                              Для продолжения нажмите Enter;\n");
    scanf("%c", &ch);
}

void input(int numOfMethod, int numOfInputMethod){
    int x = -1, y;
    float **array;
    srand(time(NULL));
    if(numOfMethod == 2 || numOfMethod == 4){
        y = 0;
        while(y != x){
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                            +-------------------------------------=<[МЕНЮ]>=---------------------------------------+\n");
            printf("                            | Введите размер квадратной матрицы: ");
            x = checkerToTen();
            if(x != -1) y = x;
        }
    }else{
        y = -1;
        while(y == -1){
            if(x != -1) printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                            +-------------------------------------=<[МЕНЮ]>=---------------------------------------+\n");
            while(x == -1){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                            +-------------------------------------=<[МЕНЮ]>=---------------------------------------+\n");
                printf("                            | Введите ширину матрицы: ");
                x = checkerToTen();
            }
            printf("                            | Введите высоту матрицы: ");
            y = checkerToTen();
        }
    }
    system("clear");
    array = malloc(y * sizeof(float *));
    for (int i = 0; i < y; i++) array[i] = malloc(x * sizeof(float));
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++) array[i][j] = 0;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++) {
            if(numOfInputMethod == 2)
                graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 0);
            else{
                graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
                usleep(40000);
            }
            switch (numOfInputMethod) {
                case 1:
                    array[i][j] = programm(i, j);
                    break;
                case 2:
                    array[i][j] = screen(i, j);
                    if(scale(maxFromArray(x, y, array), 0) > 4){
                        system("clear");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                              Введеное число не выходит из диапазона (-999;1000)\n");
                        usleep(2000000);
                        return;
                    }
                    break;
                case 3:
                    array[i][j] = file(i, j);
                    break;
                case 4:
                    array[i][j] = (float)(-500 + rand() % (1000 + 1)) + (float)((float)(rand() % 100) / 100);
                    break;
            }
        }
    system("clear");
    if(numOfInputMethod == 2)
        graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 0);
    else
        graphicCore(x, y, scale(maxFromArray(x, y, array), 0), array, 1);
    printf("\n                                              Исходный массив; \n");
    getch();
    processor(numOfMethod, x, y, array);
    free(array);
}