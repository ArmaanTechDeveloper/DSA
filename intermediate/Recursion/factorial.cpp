// Calculate factorial of a given number using recursion

#include <iostream>

using namespace std;

// n! = n * (n-1)!

int factorial(int n){
    // base case
    if(n == 0){
        return 1;
    }
    // calculation
    return n * factorial(n-1);
}
int main(){
    int n;
    cout << "Enter the number you want to get factorial of "<< endl;
    cin >> n;

    cout << "The factorial of the number "<< n << " is "<< factorial(n);
    return 0;
}