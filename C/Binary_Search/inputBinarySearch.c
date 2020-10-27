#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

bool found = false; //for breaking out the while loop

int main()
{
    int N = 0; //size of the array
    int key = 0;

    printf("Please Enter the size of the array: ");
    scanf("%i", &N);

    int arr[N];
    for (int i = 0; i < N; i++){
        printf("\(Should be in ascending order\) Input value for arr[%i]: ", i);
        scanf("%i", &arr[i]);
    }

    getchar();
    printf("Enter the value you want to search: ");
    scanf("%i", &key);

    int low = 0, high = N - 1, mid; //boundaries
    while (!found)
    {
        mid = (low + high) / 2;

        if (key > arr[high] || key < arr[low]){
            printf("Element %i not found\n", key);
            found = true;
        } else if (key < arr[mid]){
            high = mid - 1;
        } else if (key > arr[mid]){
            low = mid + 1;
        } else if (key == arr[mid]){
            printf("Element %i is present at index %i\n", key, mid);
            found = true;
        }
    }

    return 0;
}
