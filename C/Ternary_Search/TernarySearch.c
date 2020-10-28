#include <stdio.h>

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

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int left = 0;
    int right = 9;

    int p;

    int key = 100;

    if ((p = ternarySearch(left, right, key, arr)) == -1){
        printf("Element %i not found\n", key);
    } else{
        printf("The index of %i is %i", key, p);
    }

    return 0;
}
