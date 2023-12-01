// implement binary search using recursion

#include <iostream>

using namespace std;

bool binarySearch(int* arr , int s , int e , int key){
    // base case
    if(s > e){
        return false;
    }
    // calculation of mid
    int mid = s + (e-s)/2;
    // checking with target
    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] > key){
        // left part
        return binarySearch(arr , s , mid - 1 , key);
    }
    else{
        // right part
        return binarySearch(arr , mid + 1 , e , key);
    }
}

int main(){
    int arr[5] = {1,9,12,33,55};
    int size = 5;

    int target = 20;
    if(binarySearch(arr , 0 , size -1 , target)){
        cout << "Found ";
    }
    else{
        cout << "Not found ";
    }
    return 0;
}