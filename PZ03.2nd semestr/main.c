#include <stdio.h>
#include "MyFunction.h"
#include "SecondFunction.h"

int main(){
    int task;
    printf("Введите номер задания: ");
    scanf("%d", &task);
    if(task < 4)
        input(task);
    else
        input2(task);
    return 0;
}