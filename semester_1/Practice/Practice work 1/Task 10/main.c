#include <stdio.h>

int main(){
    char vehicle_sign;
    printf("Enter sign of the vehicle (c/b/m/p/t): ");
    scanf("%d", &vehicle_sign);
    switch (vehicle_sign) {
        case 'c':
            printf("Top speed: 500 km/h\n");
            break;
        case 'b':
            printf("Top speed: 60 km/h\n");
            break;
        case 'm':
            printf("Top speed: 400 km/h\n");
            break;
        case 'p':
            printf("Top speed: 1600 km/h\n");
            break;
        case 't':
            printf("Top speed: 800 km/h\n");
            break;
        default:
            printf("Incorrect sign\n");
    }
    return 0;
}
