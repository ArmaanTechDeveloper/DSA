#include <iostream>
#include <vector>

using namespace std;


void createGraphUsingArray(){
    int n , m;
    cout << "Enter the no of nodes(n) and no of edges (m)" << endl;
    cin >> n >> m;
    
    bool adj[n+1][n+1] = {false};

    // get the no of edges
    for(int i=0 ; i < m ; i ++ ){
        int u , v;
        cin >> u >> v;

        adj[u][v] = true;
        adj[v][u] = true;
    }
}


void createGraphUsingVector(){
    int n , m;
    cout << "Enter the no of nodes(n) and no of edges (m)" << endl;
    cin >> n >> m;

    vector <int> adj [n+1];

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main(){

    
    // two ways to store a graph
    // using a array

    createGraphUsingArray();

    // using a vector
    createGraphUsingVector();


    return 0;
}