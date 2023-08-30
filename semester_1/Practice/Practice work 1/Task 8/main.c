#include <stdio.h>

int main(){
    int day_of_the_week;
    printf("Enter number of day of the week: ");
    scanf("%d", &day_of_the_week);
    switch (day_of_the_week % 8) {
        case 0:
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Incorrect day\n");
    }
    return 0;
}
