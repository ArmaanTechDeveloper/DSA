// you will be given a number you have to print the digits of the number in words

#include <iostream>

using namespace std;

void sayDigits(int n , string arr[]){
    if(n <= 0){
        return ;
    }
    int digit = n % 10;
    n = n /10;

    sayDigits(n , arr);
    cout << arr[digit];
}

int main(){
    int n;
    cout << "Enter the number " << endl;
    cin >> n;

    string words[10] = {"zero " , "one " , "two " , "three " , "four ", 
    "five " , "six ", "seven ", "eight ", "nine "};

    sayDigits(n , words);

    return 0;
}