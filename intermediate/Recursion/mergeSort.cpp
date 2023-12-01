#include <iostream>

using namespace std;

void merge(int * arr , int start , int end){

    int mid = (start + end) /2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copying items to array
    int k=start;
    for(int i=0 ; i < len1 ; i++){
        first[i] = arr[k++];
    }
    for(int i=0 ; i < len2 ; i ++){
        second[i] = arr[k++];
    }

    // merge two arrays
    int index1 = 0 , index2 = 0 , mainArrayIndex = start;
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArrayIndex ++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex ++] = second[index2++];
    }
    delete [] first;
    delete [] second;

}
void mergeSort(int* arr , int start , int end){

    if(start >= end){
        return;
    }
    int mid = (start + end) /2;

    mergeSort(arr , start , mid);
    mergeSort(arr , mid+1 , end);

    merge(arr , start , end);
}

void printArray(int *arr , int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr [i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[5] = {2,4,3,5,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "before sort" << endl;
    printArray(arr , size);
    mergeSort(arr , 0 , size);
    cout << "after sort" << endl;
    printArray(arr , size);
    return 0;
}