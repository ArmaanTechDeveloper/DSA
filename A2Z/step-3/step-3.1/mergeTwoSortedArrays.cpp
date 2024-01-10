#include <bits/stdc++.h>

using namespace std;
vector < int > sortedArrayOne(vector < int > a, vector < int > b) {
    map<int , bool> mp;

    for(int i=0 ; i<a.size() ; i++){
        int elem = a[i];
        mp[elem] = true;
    }
    for(int i=0 ; i<b.size() ; i++){
        int elem = b[i];
        mp[elem] = true;
    }

    vector<int> ans;
    for(auto elem : mp){
        ans.push_back(elem.first);
    }

    return ans;

}

vector < int > sortedArrayTwo(vector < int > a, vector < int > b) {
    int n = a.size();
    int m = b.size();

    int i=0 , j=0;

    vector<int> temp;
    while(i<n && j<m){
        if(a[i] <= b[j]){
            if(temp.size() == 0 || temp.back() != a[i]){
                temp.push_back(a[i]);
            }
            i++;
        }
        else{
            if(temp.size() == 0 || temp.back() != b[j]){
                temp.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(temp.size() == 0 || temp.back() != a[i]){
            temp.push_back(a[i]);
        }
        i++;
    }
    while(j<m){
        if(temp.size() == 0 || temp.back() != b[j]){
            temp.push_back(b[j]);
        }
        j++;
    }
    return temp;
}