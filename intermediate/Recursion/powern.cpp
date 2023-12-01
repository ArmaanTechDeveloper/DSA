// Calculate 2 to the power n using recursion n >=0 

#include <iostream>

using namespace std;

// 2^n = 2 * 2^n-1

int power(int n){
    // base case
    if(n == 0){
        return 1;
    }
    // calculation
    return 2 * power(n-1);
}
int main(){
    int n;
    cout << "Enter the power n "<< endl;
    cin >> n;

    cout << "2 to the power " << n << " is "<< power(n);
    return 0;
}