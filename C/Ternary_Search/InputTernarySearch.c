#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

    int left = 0, right = N - 1;

    int p;

    if ((p = ternarySearch(left, right, key, arr)) == -1){
        printf("Element %i not found\n", key);
    } else{
        printf("The index of %i is %i", key, p);
    }

    return 0;
}


int ternarySearch(int left, int right, int key, int arr[])
{
    while (right >= left)
        {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (arr[mid1] == key){
                return mid1;
            }

            if (arr[mid2] == key){
                return mid2;
            }

            if (key < arr[mid1]){

                right = mid1 - 1;

            }else if (key > arr[mid2]){

                left = mid2 + 1;
            }else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
    return -1;
}
