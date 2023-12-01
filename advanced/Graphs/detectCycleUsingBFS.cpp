#include <vector>
#include <queue>

using namespace std;

class Solution {
  private:
    bool detectCycle(int src , vector<int> adj[] , int vis[]){
        
        // data structure for checking cycle in a graph
        queue<pair<int , int>> q;
        
        // entering the source into the queue
        q.push({src , -1});
        vis[src] = 1;
        
        // performing the algorithm
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacent : adj[node]){
                if(!vis[adjacent]){
                    // unvisited - put into the queue
                    vis[adjacent] = 1;
                    q.push({adjacent , node});
                }
                else if(parent != adjacent){
                    // if it is not a parent and someone already visited it 
                    // cycle exist
                    return true;
                }
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        // running for every component of graph
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(detectCycle(i , adj , vis)) return true;
            }
        }
        
        return false;
        
    }
};