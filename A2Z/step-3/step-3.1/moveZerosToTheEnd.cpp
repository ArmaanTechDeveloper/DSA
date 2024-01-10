#include <bits/stdc++.h>

using namespace std;

vector<int> moveZerosOne(int n, vector<int> a) {
    vector<int> temp;

    int count = 0;
    for(int i=0 ; i<n ; i++){
        if(a[i] != 0) {
            temp.push_back(a[i]);
            count ++;
        }
    }

    for(int i=count ; i<n ; i++){
        temp.push_back(0);
    }
    return temp;
}

vector<int> moveZerosTwo(int n, vector<int> a) {
    // figuring out the first 0

    int j = -1;
    for(int i=0 ; i<n ; i++){
        if(a[i] == 0){
            j=i;
            break;
        }
    }

    // moving the elements
    if(j != -1){
        for(int i=j+1 ; i<n ; i ++){
            if(a[i] != 0){
                swap(a[i] , a[j]);
                j++;
            }
        }
    }
    

    return a;
}