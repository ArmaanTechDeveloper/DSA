// You are given a array with its size check the array is sorted in increasing order or not using recursion

#include <iostream>

using namespace std;

bool checkSorted(int* arr , int size){
    // base case
    if(size == 0 || size == 1){
        return true;
    }
    // processing
    if(arr[0] > arr[1]){
        return false;
    }
    // recursive call
    return checkSorted(arr + 1 , size -1);
}

int main(){
    int arr[5] = {1,9,12,33,55};
    int size = 5;

    // print sorted or not
    if(checkSorted(arr , size)){
        cout << "Sorted ";
    }
    else{
        cout << "Not Sorted ";
    }
    return 0;
}