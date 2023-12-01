#include <iostream>
#include <queue>

using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue <int> maxHeap;
        
        for(int i=l ; i < k ; i ++){
            maxHeap.push(arr[i]);
        }
        
        // agar element heap ke maximum element se chota hai tab he na push hoga kyuki smallest nikal na hai
        for(int i=k ; i <= r ; i ++){
            int element = arr[i];
            
            if(element < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        
        return maxHeap.top();
    }
};