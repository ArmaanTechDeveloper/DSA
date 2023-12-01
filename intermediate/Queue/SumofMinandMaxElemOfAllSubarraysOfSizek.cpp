#include <iostream>
#include <queue> 

using namespace std;

int SumOfSubArray(int * arr , int n , int k){

    int sum = 0;

    for(int i=0 ; i < n-k+1 ; i ++){
        int max = INT_MIN;
        int min = INT_MAX;

        for(int j=i ; j < k+i ; j++){
            if(arr[j] <= min){
                min = arr[j];  
            } 
            if(arr[j] >= max){
                max = arr[j];
            }
        }

        sum += max + min;
    }

    return sum;

}

int main(){

    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << SumOfSubArray(arr, N, k);

    return 0;
}