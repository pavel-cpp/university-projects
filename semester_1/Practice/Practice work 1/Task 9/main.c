#include <stdio.h>

int main(){
    int number_of_card;
    printf("Enter number of card: ");
    scanf("%d", &number_of_card);
    switch (number_of_card) {
        case 6:
            printf("Six\n");
            break;
        case 7:
            printf("Seven\n");
            break;
        case 8:
            printf("Eight\n");
            break;
        case 9:
            printf("Nine\n");
            break;
        case 10:
            printf("Ten\n");
            break;
        case 11:
            printf("Jack\n");
            break;
        case 12:
            printf("Qeen\n");
            break;
        case 13:
            printf("King\n");
            break;
        case 14:
            printf("Tuz\n");
            break;
        default:
            printf("Incorrect card number\n");
    }
    return 0;
}
