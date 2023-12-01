#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) 
{
    // first loop to get the highest element to the last
    for(int i=n-1 ; i>=0 ; i--){

        // second loop to place the highest element to the last
        for(int j=0 ; j<i ;j ++){
            // swapping everytime jth element is greater than j+1 th element
            if(arr[j] > arr[j+1]) swap(arr[j] , arr[j+1]);
        }

    }
}