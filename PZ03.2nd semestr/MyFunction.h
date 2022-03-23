#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AEROFLOT{
    char destination[80];
    int number;
    char type[80];
};

struct AEROFLOT planes[7];

struct STUDENT{
    char name[80];
    int group;
    int rating[5];
};

struct STUDENT stud[10];

float GPA(int rating[10]){
    float resault;
    for (int i = 0; i < 5; ++i) {
        resault += rating[i];
    }
    resalut /= 5;
    return resault;
}

void firstTask(){
    FILE *fileStream;
    fileStream = fopen("output.txt", "w+");
    for (int i = 0; i < 10; ++i) {
        if(GPA(stud[i].rating) >= 4.0){
            printf("ФИО: %s \n Группа: %d \n", stud[i].name, stud[i].group);
            fprintf(fileStream, "ФИО: %s \n Группа: %d \n", stud[i].name, stud[i].group);
        }else{
            printf("Тупой студент!\n");
            fprintf(fileStream, "Тупой студент!\n");
        }
    }
    fclose(fileStream);
}

void secondTask(){
    for (int i = 0; i < 10; ++i) {
        int success = 0;
        for (int j = 0; j < 5; ++j) {
            if(stud[i].rating[j] == 5 || stud[i].rating[j] == 4) success = 1;
        }
        if(success)
            printf("ФИО: %s \n Группа: %d \n\n", stud[i].name, stud[i].group);
        else
            printf("Тупой студент!\n\n");
    }
}

void thirdTask(){
    for (int i = 0; i < 10; ++i) {
        int success = 0;
        for (int j = 0; j < 5; ++j) {
            if(stud[i].rating[j] == 2) success = 1;
        }
        if(success)
            printf("ФИО: %s \n Группа: %d \n\n", stud[i].name, stud[i].group);
        else
            printf("Умный студент!\n\n");
    }
}

void fourthTask(){
    char dest[80];
    int success = 0;
    printf("Введите пункт назначения: ");
    scanf("%s", dest);
    for (int i = 0; i < 7; ++i){
        if(strcmp(dest, planes[i].destination) == 0){
            printf("Номер рейса: %d       Тип самолета: %s\n", planes[i].number, planes[i].type);
            success = 1;
        }
    }
    if(!success) printf("\nВы не можете улететь!");
}

void fifthTask(){
    char type[80];
    int success = 0;
    printf("Введите тип самолета: ");
    scanf("%s", type);
    for (int i = 0; i < 7; ++i) {
        if(strcmp(type, planes[i].type) == 0){
            printf("Номер рейса: %d       Пункт назначения: %s\n", planes[i].number, planes[i].destination);
            success = 1;
        }
    }
    if(!success) printf("\nВы не можете улететь!");
}

void printInfo(){
    for (int i = 0; i < 7; ++i) {
        printf("Пункт назначения: %s        Номер рейса: %d         Тип самолета: %s\n", planes[i].destination, planes[i].number, planes[i].type);
    }
}

void switcher(int task){
    switch (task) {
        case 1:
            firstTask();
            return;
        case 2:
            secondTask();
            return;
        case 3:
            thirdTask();
            return;
        case 4:
            fourthTask();
        case 5:
            fifthTask();
        default:
            exit(EXIT_SUCCESS);
    }
}

void sort(){
    struct AEROFLOT buff;
    for (int j = 0; j < 7; ++j)
        for(int i = 0; i < 6; i++)
                if(strcmp(planes[i].destination, planes[i+1].destination) > 0){
                    buff = planes[i];
                    planes[i] = planes[i + 1];
                    planes[i + 1] = buff;
                }
}

void input2(int task){
    for (int i = 0; i < 7; ++i) {
        printf("Введите пункт назначения: ");
        scanf("%s", planes[i].destination);
        printf("Введите номер рейса: ");
        scanf("%d", &planes[i].number);
        printf("Введите тип самолета: ");
        scanf("%s", planes[i].type);
    }
    system("clear");
    if(task == 5) sort();
    printInfo();
    switcher(task);
}

void input(int task) {
    if(task == 1){
        FILE *fileStream;
        fileStream = fopen("data.txt", "r");
        for (int j = 0; j < 10; ++j) {
            fscanf(fileStream, "%s %d %d %d %d %d %d", stud[j].name, &stud[j].group, &stud[j].rating[0], &stud[j].rating[1], &stud[j].rating[2], &stud[j].rating[3], &stud[j].rating[4]);
        }
        fclose(fileStream);
    }else
        for (int i = 0; i < 10; ++i) {
            printf("Введите ФИО: ");
            scanf("%s", stud[i].name);
            printf("Введите номер группы: ");
            scanf("%d", &stud[i].group);
            printf("Введите оценки: \n");
            for (int j = 0; j < 5; ++j) {
                printf("(%d): ", (j + 1));
                scanf("%d", &stud[i].rating[j]);
            }
        }
        system("clear");
    switcher(task);
}