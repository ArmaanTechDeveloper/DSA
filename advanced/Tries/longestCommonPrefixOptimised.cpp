#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i = 0 ; i < arr[0].length() ; i ++){
        char ch = arr[0][i];

        bool match = true;
        for(int j = 1 ; j < n ; j ++){
            if( ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match){
            ans.push_back(ch);
        }
        else{
            break;
        }
    }

    return ans;
}

int main(){
    
    return 0;
}