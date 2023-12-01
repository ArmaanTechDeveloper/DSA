// most optimised way to calculate a to the power b
// You are given 2 number a and b calculate a to the power b

/*
    GOAL : a^b
    if b - odd
        a * (a^b/2 * a^b/2)
    if b - even
        a^b/2 * a^b/2
*/

#include <iostream>

using namespace std;

int AtothepowerB(int a , int b){
    // base case
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    // calculate a^b/2
    int ab2 = AtothepowerB(a , b/2);

    // what to return to calculate ?
    if(b%2 == 0){
        return ab2 * ab2;
    }
    else{
        return a * (ab2 * ab2);
    }
}

int main(){
    cout << AtothepowerB(3 , 11) << endl;
    cout << AtothepowerB(2 , 10) << endl;
    return 0;
}