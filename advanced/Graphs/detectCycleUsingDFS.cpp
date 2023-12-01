#include <vector>

using namespace std;

class Solution {
  private:
    bool detectCycle(int node , int parent , int vis[] , vector<int> adj[]){
        // marking that the node is visited
        vis[node] = 1;
        
        // getting all the adjacent nodes
        for(auto adjacent : adj[node]){
            if(!vis[adjacent]){
                // if adjacent node is not visited then visit the node and give the ans
                if(detectCycle(adjacent , node , vis , adj) == true){
                    return true;
                }
            }
            else if(parent != adjacent){
                // if the node is visited and parent != adjacent 
                // then node is visited early
                return true;
            }
        }
        
        // if cycle not found return false
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        
        // for disconnected components
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(detectCycle(i , -1 , vis , adj) == true ) return true;
            }
        }
        
        return false;
        
    }
};