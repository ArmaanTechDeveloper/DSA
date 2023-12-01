// You are given a array with its size return the total sum of the array

#include <iostream>

using namespace std;

int sum(int *arr , int size){
    // base case
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    // recursive call
    return arr[0]+sum(arr +1 , size -1);
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;

    cout << sum(arr , size);
    return 0;
}