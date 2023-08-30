#include <stdio.h>

int main(){
    const int answer = 1703;

    printf("What year was Saint Petersburg founded?\n");
    printf("Enter the purchase amount and press <Enter>\n");

    int user_answer;
    scanf("%d", &user_answer);
    if(user_answer == answer){
        printf("Congratulations");
    }else{
        printf("You made a mistake, the correct answer is: %d", answer);
    }
    return 0;
}
