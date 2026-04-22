#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    double num_a, num_b, answer = 0;
    char oper, retype;
    int valid = 1;

    printf(" __________ \n"
            "| ________ |\n"
            "||12345678||\n"
            "|\"\"\"\"\"\"\"\"\"\"|\n"
            "|[M|#|C][-]|\n"
            "|[7|8|9][+]|\n"
            "|[4|5|6][x]|\n"
            "|[1|2|3][%%]|\n"
            "|[.|O|:][=]|\n"
            "\"----------\"\n"
            "A simple calculator made in C!\n\n");

    printf("Enter first number: ");
    if (scanf("%lf", &num_a) != 1) { // this means if it cant be read
        printf("Hey, please type a real number in");
        valid = 0;
        // ik, for robustness i should make it a char and if its not a number
        // then i should give error, else convert into int or smth like that
        // but im not that good in C :(
    }

    printf("Enter second number: ");
    if (scanf("%lf", &num_b) != 1) { // this means if it cant be read
        printf("Hey, please type a real number in");\
        valid = 0;
    }

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &oper);
    
    char lower_oper = tolower(oper);

    if (lower_oper == '+' || lower_oper == 'p' || lower_oper == 'a') {
        answer = num_a + num_b;
    } else if (lower_oper == '-' || lower_oper == 'm' || lower_oper == 's') {
        answer = num_a - num_b;
    } else if (lower_oper == '*' || lower_oper == 'x' || lower_oper == 't') {
        answer = num_a * num_b;
    } else if (lower_oper == '/' || lower_oper == 'd') {
        if (num_b != 0) {
            answer = num_a / num_b;
        } else {
            printf("Uhh, you can't divide by 0...\n");
            printf("Wanna retype number b? (y/n): ");
            scanf(" %c", &retype);
            if (tolower(retype) == 'y') {
                printf("Enter new second number: ");
                scanf("%lf", &num_b);
                answer = num_a / num_b;
            } else {
                printf("Ohh, ok then :( goodbye\n");
                valid = 0;
            }
        }
    } else {
        printf("Huh? I didn't really get that... \n");
        printf("Debug: num_a: %lf, num_b: %lf, oper: %c\n", num_a, num_b, oper);
        valid = 0;
    }

    if (valid) {
        printf("\nResult: %lf %c %lf = %lf!\n", num_a, oper, num_b, answer);
    } else {
        printf("\nOperation could not be completed.\n");
    }

    return 0; 
}