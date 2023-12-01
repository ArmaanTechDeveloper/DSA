// Reverse a string using stack

#include <iostream>
#include <stack>


using namespace std;

int main(){
    
    string unreversed = "love";
    cout << "Unreversed String : " << unreversed << endl;

    stack <char> st;
    int len = unreversed.length();

    for(int i = 0 ; i < len ; i ++){
        st.push(unreversed[i]);
    }

    string reversed = "";

    while(!st.empty()){
        char ch = st.top();
        reversed = reversed + ch;
        st.pop();
    }

    cout << "Reversed String is : " << reversed;

    return 0;
}