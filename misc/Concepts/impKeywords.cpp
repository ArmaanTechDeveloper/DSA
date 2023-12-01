#include <iostream>

using namespace std;

#define PI 3.14 // creating a macro
// macro will be replaced everywhere in the program when the program compiles


int score = 144; // global variable
// BAD PRACTICE  - any function can change its value use reference variable instead
void scoreUpdate(){
    score ++;
}

/*
    INLINE FUNCTIONS 
    functions which are one liner , the one line gets replaced in code everywhere just like macro when the program compiles
*/

inline double calculateArea(int& r){
    return PI * r * r;
}

/*
    Default Arguments
    Arguments in a function which are option someone may pass or may not pass
    if someone passes a value then the value is passed value only
    if not then the functin takes default value assigned to it
    works only from right to left

*/

void printArray(int arr[] , int n , int start = 0){

    for(int i=start; i < n; i ++){
        cout << arr[i] << " ";
    }cout <<endl;
}
int main(){

    int r = 5;
    cout << "Area is " << PI * r * r << endl;

    scoreUpdate();
    cout << "The value of score is "<< score << endl;

    cout << "Area is from the INLINE FUNCTION " << calculateArea(r) << endl;

    int arr[5] = {1 , 2 , 3 , 4 , 5 };
    // with arguments
    printArray(arr , 5 , 1);
    // without arguments
    printArray(arr , 5 );


    return 0;
}