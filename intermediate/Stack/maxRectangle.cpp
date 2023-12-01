/*You are required to complete this method*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
  private:
    vector<int> nextSmallerElement(int * heights , int n){

        stack <int> st;
        st.push(-1);

        vector <int> ans(n);
        for(int i=n-1 ; i >= 0 ; i--){

            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;

    }
    
    vector<int> prevSmallerElement(int * heights , int n){

        stack <int> st;
        st.push(-1);

        vector <int> ans(n);
        for(int i=0 ; i < n ; i++){

            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;

    }
    
    int largestRectangleArea(int * heights , int m) {
        int n = m;

        vector <int> prev(n);
        prev = prevSmallerElement(heights , n);
        vector <int> next(n);
        next = nextSmallerElement(heights , n);

        int area = INT_MIN;
        for(int i=0 ; i < n ; i ++){

            int l = heights[i];

            if(next[i] == -1){
                next[i] = n;
            }

            int b = next[i] - prev[i] -1;

            int newArea = l*b;
            area = max(area , newArea);

        }

        return area;

    }
  public:
    int maxArea(int* M[], int n, int m) { // change this
        
        // step 1 : compute first row area
        
        int area = largestRectangleArea(M[0] , m);
        
        // step 2 : compute for the next rows
        
        for(int i=1 ; i < n ; i ++){
            for(int j=0; j < m ; j ++){
                
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else{
                    M[i][j] = 0;
                }
                
            }
            
            area = max(area , largestRectangleArea(M[i] , m));
        }
        
        return area;
    }
};