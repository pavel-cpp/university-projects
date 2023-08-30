#include <stdio.h>

int main(){
    int first_number;
    int second_number;
    int third_number;

    printf("Введите 3 числа: ");
    scanf("%d %d %d", &first_number, &second_number, &third_number);

    int result;

    if(first_number > second_number && first_number > third_number){
        result = first_number;
    }else if(second_number > first_number && second_number > third_number){
        result = second_number;
    }else if(third_number > second_number && third_number > first_number){
        result = third_number;
    }else{
        printf("Все числа равны\n");
        return 1;
    }
    printf("Число %d максимальное!\n", result);
    return 0;
}
