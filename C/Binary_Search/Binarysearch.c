#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define N 10 //size of the array
int low = 0, high = N - 1, mid; //boundaries
bool found = false; //return value

int main()
{
    int arr[N] = {1,2,3,4,5,6,7,8,9,10};
    int key = 99;

    while (!found)
    {
        mid = (low + high) / 2;

        if (key > arr[high] || key < arr[low]){
            printf("Element not found");
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
