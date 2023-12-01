//function Template for C++
#include <iostream>
#include <queue>

using namespace std;
//Function to reverse the queue.
class Solution
{
    private:
    
    void solve(queue <int> & q){
        
        if(q.empty()){
            return;
        }
        
        int element = q.front();
        q.pop();
        
        solve(q);
        
        q.push(element);
    }
    public:
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
        
        
    }
};