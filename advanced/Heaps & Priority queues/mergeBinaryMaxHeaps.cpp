#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void heapify(vector <int>& arr , int size , int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < size && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < size && arr[largest] < arr[right]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[largest] , arr[i]);
            heapify(arr , size , largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector <int> result;
        for(auto i : a){
            result.push_back(i);
        }
        for(auto i : b){
            result.push_back(i);
        }
        
        int size = result.size();
        
        for(int i = size /2 -1; i >= 0 ; i --){
            heapify(result , size , i);
        }
        
        
        return result;
        
    }
};