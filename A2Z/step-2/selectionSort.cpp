#include <vector>

using namespace std;

void selectionSort(vector<int>&arr) {
    // getting the size of the array
    int n = arr.size();

    // first loop for getting the first element
    for(int i=0 ; i<n ;i ++){
        int mini = i;

        // second loop for getting the minimum element in the rest of the array
        for(int j=i+1 ; j<n ;j++){
            if(arr[j] < arr[mini]) mini = j;
        }

        // swap the minimum element with the i'th element
        swap(arr[mini] , arr[i]);
    }
}