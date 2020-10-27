#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    //declare variables
    int row, col, i, j;
    int arr[50][50];

    //user input number of rows
    printf("Enter the number of rows: ");
    scanf("%i", &row);

    //user input number of columns
    getchar();
    printf("Enter the number of columns: ");
    scanf("%i", &col);

    //storing input in row major form...
    for (i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("Enter value for arr[%i][%i]: ", i, j);
            scanf("%i", &arr[i][j]);
        }
    }

    //printing values of array...
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("\t%i,", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
