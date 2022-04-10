#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

float a = 50, b = 0.07, c = 0.1, tn = 15, t1 = 30, t2 = 50, tk = 100;

void zast(){
    FILE *f=fopen("zast.txt","r");
    char ch;
    while (!feof(f))
    {
        fscanf(f,"%c",&ch);
        printf("%c",ch);
    }
    fclose(f);
    printf("\n");
    sleep(5);
}

float Uvx(float t){
    if(t <= t1) return a*(1-exp(-b*(t - tn)));
    if(t1 < t && t <= t2) return a*(1-exp(-b*(t1 - tn)))-(t-t1);
    if(t > t2) return (a*(1-exp(-b * (t1 - tn)))-(t2-t1))*exp(-c*(t-t2));
    return 0;
}

float Uvix(float t){
    if(Uvx(t)<=10) return 5;
    if(Uvx(t) > 10) return (b*pow(Uvx(t), 2));
    return 0;
}

float duration(float t, int N){
    float Umax = t, Umin = Umax, dt = (tk - tn) / N;
    for (float i = tn; round(i) <= tk; i += dt) {
        if(Umax < Uvix(i)) Umax = Uvix(i);
        if(Umin > Uvix(i)) Umin = Uvix(i);
    }
    float Uimp = (Umin + 0.5*(Umax-Umin)), dlit=0;
    for (float i = tn; round(i) <= tk; i += dt)
        if (Uvix(i) >= 0.5 * (Umax - Umin)) dlit+=dt;
    return dlit;
}

void fout(float t[], int N){
    FILE *f1,*f2,*f3;
    f1=fopen("massiv_t.txt","w");
    f2=fopen("massiv_Uvx.txt", "w");
    f3=fopen("massiv_Uvix.txt", "w");
    for (int i=0;i<N;i++){
        fprintf(f1,"%.3f\n", t[i]);
        fprintf(f2,"%.3f\n", Uvx(t[i]));
        fprintf(f3,"%.3f\n", Uvix(t[i]));
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void checkCalculationForNPoints(int N){
    int  num = 0;
    float dt = (tk - tn) / (N - 1);
    float t[N];
    printf("№       t       Uvx         Uvix\n");
    for(float i = tn; round(i) <= tk; i += dt){
        t[num] = i;
        printf("%d      %.3f       %.3f         %g\n", (num+1), i, Uvx(i), Uvix(i));
        num++;
    }
}

void calculationOfAParameterWithAGivenAccuracy(int N){
    printf("Длительность импульса сигнала: %.3f     Погрешность: %.3f\n", duration(Uvix(0), N), fabs(duration(Uvix(0), 171) - duration(Uvix(0), N)) / duration(Uvix(0), N));
}

void fileoutput(int N){
    int  num = 0;
    float dt = (tk - tn) / (N - 1), t[N];
    for(float i = tn; round(i) <= tk; i += dt){
        t[num] = i;
        num++;
    }
    fout(t, N);
}

int start(char ch) {
    if(ch != '1' && ch != '2' && ch != '3'){
        system("./start.sh");
        exit(EXIT_SUCCESS);
    }
    system("clear");
    int N = 10;
        printf("Введите количество точек: ");
        scanf("%d", &N);
        system("clear");
    switch (ch) {
        case '1':
            checkCalculationForNPoints(N);
            return 0;
        case '2':
            calculationOfAParameterWithAGivenAccuracy(N);
            return 1;
        case '3':
            fileoutput(N);
            printf("Запись в файл прошла успешно!\n");
            return 2;
    }
    return 0;
}
