#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    
    int largest = a[0] , secondLargest = -1;
    int smallest = a[0] , secondSmallest = INT_MAX;
    
    for(int i=0 ; i<n ; i++) {
        if(a[i] > largest){
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > secondLargest){

            // if the element is smaller than largest but larger than second largest
            secondLargest = a[i];
        }

        if(a[i] < smallest){
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < secondSmallest){

            // if the element is not the smallest but less than second smallest
            secondSmallest = a[i];
        }
    }

    return {secondLargest , secondSmallest};


}
