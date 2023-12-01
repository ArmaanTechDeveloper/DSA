#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // creating a adjacency list
    vector <vector <int>> adj(V);

    for(int i=0 ; i<E ; i ++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Data structure for DFS
    vector <bool> visited(V , 0);
    vector <vector <int> > result;

    for(int i=0 ; i < V ; i ++ ){
        if(!visited[i]){
            stack <int> st;
            vector <int> component;
            st.push(i);

            while(!st.empty()){
                int node = st.top();
                st.pop();

                if(!visited[node]){
                    visited[node] = true;
                    component.push_back(node);

                    // push the neighbours of that node
                    for(auto it : adj[node]){
                        if(!visited[it]){
                            st.push(it);
                        }
                    }
                }
            }

            if(!component.empty()){
                result.push_back(component);
            }
        }
    }

    return result;
}