#include <vector>
#include <set>

using namespace std;

class Solution {
  private:
    void dfs(int row , int col ,vector<vector<int>> & vis, vector<vector<int>> & grid , 
    vector<pair<int,int>> & temp , int delrow[] , int delcol[] , int brow , int bcol){
        
        vis[row][col] = 1;
        
        temp.push_back({row - brow , col - bcol});
        
        int n = grid.size();
        int m = grid[0].size();
        
        // movement in 4 directions
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow , ncol , vis , grid , temp , delrow , delcol , brow , bcol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        // getting n and m
        int n = grid.size();
        int m = grid[0].size();
        
        // preparing the data structure
        vector<vector<int>> vis(n , vector<int> (m , 0));
        set<vector<pair<int , int>>> st;
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    
                    // list for storing the coordinates
                    vector<pair<int,int>> temp;
                    dfs(i , j , vis , grid , temp , delrow , delcol , i , j);
                    st.insert(temp);
                    
                }
            }
        }
        
        return st.size();
        
        
    }
};