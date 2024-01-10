
#include <vector>
#include <list>

using namespace std;

vector<int> rotateArrayOne(vector<int>& arr, int n) {
    vector<int> temp(n);
    for(int i=1 ; i<n ; i ++){
        temp[i-1] = arr[i];
    }

    temp[n-1] = arr[0];

    return temp;
}


vector<int> rotateArrayTwo(vector<int>& arr, int n) {
    list<int> li;

    for(int i=0 ; i<n ; i++){
        li.push_back(i);
    }


    // generating the index
    int first = li.back();
    li.pop_back();
    li.push_front(first);

    vector<int> temp(n);

    for(int i=0 ; i<n ; i ++){
        int index = li.front();
        li.pop_front();

        temp[index] = arr[i];
    }

    return temp;

}