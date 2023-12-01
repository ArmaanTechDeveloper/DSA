
using namespace std;

void insertionSort(int arr[], int n)
{
    // for loop to get the element which is to be placed in the correct position 
    for(int i=0 ; i<n ; i++){

        // element is arr[i]

        int j=i;

        // while loop to place the element into the correct position

        while(j>0 && arr[j-1] > arr[j]){
            // simple swapping
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;

            // decrement
            j--;
        }
    }
}