#include <bits/stdc++.h>

using namespace std;

vector<int> rotateArrayOne(vector<int>arr, int k) {
    list<int> li;
    int n = arr.size();

    for(int i=0 ; i<n ; i++){
        li.push_back(i);
    }


    for(int i=0 ; i<k ; i ++){
        int first = li.back();
        li.pop_back();
        li.push_front(first);
    }
    
    vector<int> temp(n);

    for(int i=0 ; i<n ; i ++){
        int index = li.front();
        li.pop_front();

        temp[index] = arr[i];
    }

    return temp;
}


// second more optimsed approach

void reverseElements(vector<int>& arr , int start , int end){
    
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start ++;
        end --;
    }

}   

vector<int> rotateArrayTwo(vector<int>arr, int k) {
    int n = arr.size();

    int d = k%n;
    reverseElements(arr, 0, d-1);
    reverseElements(arr, d, n-1);
    reverseElements(arr, 0, n-1);

    return arr;
}
