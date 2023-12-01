#include <vector>

using namespace std;

class Solution {
  private:
    void dfs(int row , int col ,vector<vector<int>> & grid, vector<vector<int>> & vis , int delrow[] , int delcol[]){
        vis[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        // check for four directions
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>= 0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow , ncol , grid , vis , delrow , delcol);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // preparing the data structure
        vector<vector<int>> vis(n , vector<int> (m , 0));
        
        int delrow[] = {-1 , 0 , +1 , 0};
	    int delcol[] = {0 , +1 , 0 , -1};
        
        // traversing the columns
	    for(int i=0 ; i<n ; i++){
	        
	        // for the first column
	        if(grid[i][0] == 1 && !vis[i][0]){
	            dfs(i , 0 , grid , vis , delrow , delcol);
	        }
	        
	        // for the last column
	        if(grid[i][m-1] == 1 && !vis[i][m-1]){
	            dfs(i , m-1 , grid , vis , delrow , delcol);
	        }
	    }
	    
	    // traversing the rows
	    for(int j=0 ; j<m ; j++){
	        
	        // for the first row
	        if(grid[0][j] == 1 && !vis[0][j]){
	            dfs(0 , j , grid , vis , delrow , delcol);
	        }
	        
	        // for the last row
	        if(grid[n-1][j] == 1 && !vis[n-1][j]){
	            dfs(n-1 , j , grid , vis , delrow , delcol);
	        }
	    }
	    
	    int cnt = 0;
	    // checking for the no of ones left
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            if(grid[i][j] == 1 && !vis[i][j]){
	                cnt ++;
	            }
	        }
	    }
	    
	    return cnt;
    }
};