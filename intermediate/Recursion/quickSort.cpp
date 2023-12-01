#include <iostream>

using namespace std;

int partition(int *arr , int s , int e){

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1 ; i <= e ; i++){
        if(arr[i] <= pivot){
            cnt ++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[s] , arr[pivotIndex]);

    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i ++;
        }
        while(arr[j] > pivot){
            j --;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;

}

void quickSort(int *arr , int s , int e){

    // base case
    if(s>=e){
        return;
    }

    // creating partition and arranging left size less than pivot and right side greater than pivot
    int p = partition(arr , s , e);

    // left part sorting
    quickSort(arr , s , p-1);

    // Right part sorting
    quickSort(arr , p+1 , e);
}

void printArray(int *arr , int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr [i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[5] = {2,4,3,5,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "before Sorting" << endl;
    printArray(arr , size);

    quickSort(arr , 0 , 4);

    cout << "after Sorting" << endl;
    printArray(arr , size);

    return 0;
}