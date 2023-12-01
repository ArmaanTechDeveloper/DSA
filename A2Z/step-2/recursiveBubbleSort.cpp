void bubbleSort(int arr[], int n) 
{
    // base case for the recursive function
    if(n < 0 ) return;

    // loop to sort n length array
    // place the greatest element into the last position
    for(int i=0 ; i<n-1 ; i++){
        if(arr[i] > arr[i+1]){
            // simple swapping algorithm
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    bubbleSort(arr, n-1);

}