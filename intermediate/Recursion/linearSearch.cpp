// You are given a array with size and target 
// apply linear search using recursion to find that the target is present in array or not


#include <iostream>

using namespace std;

bool linearSearch(int* arr ,int size ,int target){
    // base case
    if(size == 0){
        return false;
    }
    // checking
    if(arr[0] == target){
        return true;
    }
    // recursive call
    return linearSearch(arr + 1 , size - 1 , target);

}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;
    int target = 6;
    
    if(linearSearch(arr , size , target)){
        cout << "Found ";
    } 
    else{
        cout << "Not found ";
    }
    return 0;
}