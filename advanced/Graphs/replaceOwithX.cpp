#include <vector>

using namespace std;

class Solution{
    
private:
    void dfs(int row , int col , vector<vector<char>> mat , vector<vector<int>> & vis,
                int delrow[] , int delcol[]){
        
        vis[row][col] = 1;
        
        // compute the size
        int n = mat.size();
        int m = mat[0].size();
        
        // traverse in all four diretions
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>= 0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
            && mat[nrow][ncol] == 'O'){
                dfs(nrow , ncol , mat , vis , delrow , delcol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // preparing the data structure
        vector<vector<int>> vis(n , vector<int>(m , 0));
        
	    int delrow[] = {-1 , 0 , +1 , 0};
	    int delcol[] = {0 , +1 , 0 , -1};
	    
	    
	    // traversing the columns
	    for(int i=0 ; i<n ; i++){
	        
	        // for the first column
	        if(mat[i][0] == 'O' && !vis[i][0]){
	            dfs(i , 0 , mat , vis , delrow , delcol);
	        }
	        
	        // for the last column
	        if(mat[i][m-1] == 'O' && !vis[i][m-1]){
	            dfs(i , m-1 , mat , vis , delrow , delcol);
	        }
	    }
	    
	    // traversing the rows
	    for(int j=0 ; j<m ; j++){
	        
	        // for the first row
	        if(mat[0][j] == 'O' && !vis[0][j]){
	            dfs(0 , j , mat , vis , delrow , delcol);
	        }
	        
	        // for the last row
	        if(mat[n-1][j] == 'O' && !vis[n-1][j]){
	            dfs(n-1 , j , mat , vis , delrow , delcol);
	        }
	    }
	    
	    // converting all the O ' s
	    
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            if(!vis[i][j] && mat[i][j] == 'O'){
	                mat[i][j] = 'X';
	            }
	        }
	    }
	    
	    return mat;
    }
};