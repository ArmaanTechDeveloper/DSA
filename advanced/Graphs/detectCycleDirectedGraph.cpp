#include <vector>

using namespace std;

class Solution {

  private:
    bool dfsCheck(int node , vector<int> adj[] , int visited[] , int pathVisited[]){
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                // if adjacent node is not visited then visit the node
                if(dfsCheck(it , adj , visited , pathVisited) == true) return true;
            }
            else if(pathVisited[it]){
                // if adjacent node is visited and also path visited
                return true;
                
            }
        }
        
        // backtracking 
        pathVisited[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        int visited[V] = {0};
        int pathVisited[V] = {0};
        
        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                if(dfsCheck(i , adj , visited , pathVisited) == true) return true;
            }
        }
        
        return false;
    }
};