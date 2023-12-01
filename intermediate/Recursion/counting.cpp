// You are given a number n print 1 to n and n to 1 using recursion

#include <iostream>

using namespace std;

// Head recursion
// pehle stack mein ghusao phir print karwao
void increasingCounting(int n){

    // base case
    if(n == 0){
        return ;
    }
    // recursive call
    increasingCounting(n - 1);
    cout << n << endl;

}

// tail recursion 
// pehle print karwao phir stack mein ghusao
void decreasingCounting(int n){

    // base case
    if (n == 0){
        return ;
    }
    cout << n << endl;
    // recursive call
    decreasingCounting(n - 1);
}
int main(){
    int n;
    cout << "Enter the number you want to print counting "<< endl;
    cin >> n;

    // n to 1
    cout << "Printing decreasing counting "<< endl;
    decreasingCounting(n);

    // 1 to n
    cout << "Printing the increasing counting" << endl;
    increasingCounting(n);
    return 0;
}