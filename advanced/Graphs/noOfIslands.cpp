#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    void bfs(int i , int j , vector<vector<int>> & vis , vector<vector<char>> & grid){
        vis[i][j] = 1;
        
        queue <pair<int , int>> q;
        q.push({i , j});
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        // do the bfs traversal
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // for calculating the 8 directions
            for(int delrow=-1 ; delrow <= 1 ; delrow ++){
                for (int delcol=-1 ; delcol <= 1 ; delcol ++){
                    int newrow = row + delrow;
                    int newcol = col + delcol;
                    
                    if( newrow >=0 && newrow < n && newcol >= 0 && newcol < m &&
                        !vis[newrow][newcol] && grid[newrow][newcol] == '1'){
                            
                        bfs(newrow , newcol , vis , grid);
                    }
                }   
            }
        }
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        int cnt = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){

                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt ++;
                    bfs(i , j , vis , grid);
                }
                
            }
        }
        
        return cnt;
    }
};