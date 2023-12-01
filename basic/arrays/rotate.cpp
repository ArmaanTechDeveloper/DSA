// problem : https://shorturl.at/jLMS9

#include <iostream>

using namespace std;
#include <list>


void rotateArray(int *arr , int k , int size){
    
    list <int> l;

    int temp[size];
    int index = 0;
    for(int i =0 ; i < size ; i ++){
        l.push_back(i);
    }
    for(int i = 0 ; i < k ; i++){
        int firstElement = l.front();
        l.pop_front();
        l.push_back(firstElement);
    }
    for(int i:l){
        temp[index] = arr[i];
        index ++;
    }
    for(int i=0 ; i < size ; i ++){
        cout << temp[i] << " ";
    }

}

int main(){
    
    int arr[4] = {5,6,7,8};
    int k = 3;

    rotateArray(arr , k , 4); 

    
    return 0;
}