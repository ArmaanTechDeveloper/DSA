// You are given a string check the string is palindrome or not using recursion

#include <iostream>

using namespace std;

bool checkPalindrome(string str , int i , int j){
    // end case
    if(i > j ){
        return true;
    }
    // if not matches then return false
    if(str[i] != str[j]){
        return false;
    }
    i ++;
    j --;
    return checkPalindrome(str , i , j);
}

int main(){
    string name = "abbcbba";
    cout << checkPalindrome(name , 0 , name.length() - 1) << endl;

    string notPalindrome = "abhishek";
    cout << checkPalindrome(notPalindrome , 0 , notPalindrome.length() -1 ) << endl;
    return 0;
}