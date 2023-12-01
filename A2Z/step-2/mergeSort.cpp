#include <vector>

using namespace std;

// merge both the arrays
void merge(int arr[] , int low , int mid , int high ){

    int left = low;
    int right = mid +1;

    vector<int>  temp;


    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left ++;
        }
        else{
            temp.push_back(arr[right]);
            right ++;
        }
    } // after thsi while loop completion one array will be exhausted

    // getting all the items if the left part is left
    while(left <= mid){
        temp.push_back(arr[left]);
        left ++;
    }

    // getting all the items if the right part is left
    while(right <= high){
        temp.push_back(arr[right]);
        right ++;
    }

    // copying all the elements to arr

    // why  i-low
    // assume i as 3 & low as 2
    // then i will give you 3
    // but i-low will give you 1 (which is the correct index in which it is stored)
    for (int i = low; i <= high; i++) {

        arr[i] = temp[i - low];
    }
}


void mergeSort(int arr[], int l, int r) {
    if(l>=r) return;

    int mid = (l+r)/2;

    // for the left part
    mergeSort(arr, l, mid);

    // for the right part
    mergeSort(arr, mid+1, r);

    // merge both the arrays
    merge(arr , l , mid , r);
}