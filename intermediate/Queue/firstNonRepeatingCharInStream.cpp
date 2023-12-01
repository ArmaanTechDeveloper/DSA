#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map <char , int> count;
		    queue <char> q;
		    
		    string ans = "";
		    for(int i=0 ; i < A.length() ; i ++){
		        char ch = A[i];
		        count[ch] ++;
		        q.push(ch);
		        
		        while(!q.empty()){
    		        if(count[q.front()] >1){
    		            q.pop();
    		        }
    		        else{
    		            break;
    		        }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');
		        }
		        else{
		            ans.push_back(q.front());
		        }
		    }
		    
		    return ans;
		}

};