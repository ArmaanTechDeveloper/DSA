// Sort a array using bubble sort technique using recursion 

#include <iostream>

using namespace std;

// print the array
void printArray(int *arr , int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr [i] << " ";
    }
    cout << endl;
}

// sorting the array
void bubbleSort(int *arr , int size){
    // base case
    if(size == 0 || size == 1){
        return ;
    }
    // placing largest element to the right
    for(int i=0 ; i < size - 1; i ++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }
    // RECURSIVE CALL
    bubbleSort(arr , size - 1);
}

int main(){
    int arr[5] = {5,2,3,4,1};
    bubbleSort(arr , 5);
    printArray(arr , 5);

    return 0;
}