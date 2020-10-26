#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

//declaring variables
bool endApp = false;
char operator;
float result = 0, a = 0, b = 0;
char s;
char e;

/*I'm using getchar(); every after scanf();
 *to avoid errors in the iostream.*/


//doOperation function
int calculator()
{
    //logic for the calculation
    switch (operator) //using switch statement to do the operation
    {
        case '+':
            result = a + b;
            printf("\nThe result is %lf\n\n", result);
            break;
        case '-': //to not return negative values
            if (a >= b){
                result = a - b;
                printf("\nThe result is %lf\n\n", result);
            }else {
                printf("INVALID INPUT\n");
            }
            break;
        case '*':
            result = a * b;
            printf("\nThe result is %lf\n\n", result);
            break;
        case '/': //divisor can't be 0
            if (b != 0){
                result = a / b;
                printf("\nThe result is %lf\n\n", result);
            }else {
                printf("INVALID INPUT\n");
            }
            break;
    }
    return result;
}

//exit function
void Exit()
{
    getchar();
    printf("\nDo you want to exit? Y/N: ");
    scanf("%c", &s);

    if(s == 'Y' || s == 'y'){
        endApp = true;
        printf("\n\nTHE PROGRAM IS QUITING...");
    } else if(s == 'N' || s == 'n'){
        endApp = false;
    } else{
        printf("\n\nWhat the heck are you doing?");
        endApp = false;
    }
    getch();
    system("cls");
    getchar();
}


//main function
int main()
{
    while (!endApp)
    {
        //starting the program...
        printf("THE PROGRAM IS STARTING...\n\n");

        //describing the program
        printf("This is a simple calculator.\n");

        //prompt the user to input two numbers
        int num1 = 0;
        while (num1 == 0){ //return to prompt if user enters invalid input
            printf("Please enter a number: ");
            int check1 = scanf("%f", &a);

                if(check1 != 1){
                    num1 = 0;
                    printf("INVALID INPUT\n");
                    getchar();
                    getch();
                    system("cls");
                    continue;
                }else { //breaking out of the loop, if user enters correct input
                    num1 = 1;
                }
        }

        int num2 = 0;
        while (num2 == 0){ //return to prompt if user enters invalid input
            printf("Please enter another number: ");
            int check2 = scanf("%f", &b);

                if(check2 != 1){
                    num2 = 0;
                    printf("INVALID INPUT\n");
                    getchar();
                    getch();
                    system("cls");
                    continue;
                }else { //breaking out of the loop, if user enters correct input
                    num2 = 1;
                }
        }

        //prompt the user to choose operand
        getchar();
        int num3 = 0;
        while (num3 == 0){ //return to prompt if user enters invalid input
            printf("Choose the operation, '+, -, *, /': ");
            int check3 = scanf("%c", &operator);

                if(check3 != 1){
                    num3 = 0;
                    printf("INVALID INPUT");
                    getchar();
                    getch();
                    system("cls");
                    continue;
                }else { //breaking out of the loop, if user enters correct input
                    num3 = 1;
                }
        }

        //do calculation
        getchar();
        calculator();
        Exit();
    }

    return 0;
}
