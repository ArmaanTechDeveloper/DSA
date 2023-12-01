#include <queue>
#include <vector>

using namespace std;

class Solution {
    
private:
    bool checkSingleComponent(int start , int v , vector<int>adj[] , int col[]){
        
        // check for single component
        queue<int> q;
        q.push(start);
        col[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(col[it] == -1){
                    // if node is not colored yet
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]){
                    // if node is colored but has same color
                    return false;
                }
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    // colors array
	    int color[V];
	    
	    // initializing the uncoloured as -1
	    for(int i=0 ; i<V ; i++) color[i] = -1;
	    
	    // checking for every component
	    for(int i=0 ; i<V ; i++){
	        if(color[i] == -1){
	            if(checkSingleComponent(i , V , adj , color) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};