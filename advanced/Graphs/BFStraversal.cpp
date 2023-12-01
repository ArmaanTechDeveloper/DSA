#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector <int> bfs;
    queue <int> q;

    int vis[n] = {0};

    q.push(0);
    vis[0] = 1;


    while(!q.empty()){

        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }

    }

    return bfs;
}