//User function template for C++

#include <vector>
#include <stack>
#include <iostream>

using namespace std;
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step 1 : push 0 to n into stack
        stack <int> st;
        for(int i=0 ; i < n ; i ++){
            st.push(i);
        }
        
        
        // get 2 elements and check if they know or not
        
        while(st.size() > 1){
            
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            // check if A know B or not
            
            if(M[a][b] == 1){
                // a knows b -> a cannot be a celebrity
                st.push(b);
            }
            else{
                st.push(a);
            }
            
        }
        
        int maybeCeleb = st.top();
        
        // step 3 : check if maybe celebrity is a celebrity or not
        
        // row check everything should be 0
        for(int i=0 ; i < n ; i ++){
            if(M[maybeCeleb][i] == 1){
                return -1;
            }
        }
        
        // column check everything should be 1 except diagonal element
        
        for(int i=0 ; i < n ; i ++ ){
            if(i!=maybeCeleb && M[i][maybeCeleb] == 0){
                return -1;
            }
        }
        
        // maybe Celeb is a celebrity so return it
        return maybeCeleb;
    }

    int main(){
        return 0;
    }
};