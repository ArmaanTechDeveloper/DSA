#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int start , int c , vector<int> adj[] , int col[]){
        col[start] = c;
        
        for(auto it: adj[start]){
            if(col[it] == -1){
                if(dfs(it , !c , adj , col) == false) return false;
            }
            else if(col[it] == c){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    int color[V];
	    for(int i=0 ; i<V ; i++) color[i] = -1;
	    
	    for(int i=0 ; i<V ; i++){
	        if(color[i] == -1){
	            if(dfs(i , 0 , adj , color) == false) return false;
	        }
	    }
	    
	    return true;
	}

};