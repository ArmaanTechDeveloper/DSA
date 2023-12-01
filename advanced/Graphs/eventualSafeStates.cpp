#include <vector>

using namespace std;

class Solution {
private:
    bool dfsCheck(int node , vector<int> adj[] , int visited[] , int pathVisited[] , int check[]){
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                // if adjacent node is not visited then visit the node
                if(dfsCheck(it , adj , visited , pathVisited , check) == true) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[it]){
                // if adjacent node is visited and also path visited
                check[node] = 0;
                return true;
                
            }
        }
        
        // backtracking 
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // using the cycle detection technique
        
        int visited[V] = {0};
        int pathVisited[V] = {0};
        int check[V] = {0};
        
        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                dfsCheck(i , adj , visited , pathVisited , check);
            }
        }
        
        
        vector <int> ans;
        for(int i=0 ; i<V ; i++){
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};