#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    
    stack <int> st;
    int n = q.size();
    
    for(int i=0 ; i<k ; i ++){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    int kabtak = n - k;
    
    for(int i=0 ; i < kabtak ; i++){
        int element = q.front();
        q.push(element);
        q.pop();
    }
    
    return q;
    
}
