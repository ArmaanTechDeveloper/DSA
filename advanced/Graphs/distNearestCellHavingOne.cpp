#include <vector>
#include <queue>

using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // getting the rows and column
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    // preparing the data structure for solving
	    vector<vector<int>> distance(n , vector<int> (m , 0));
	    vector<vector<int>> vis(n , vector<int> (m , 0));
	    queue< pair< pair<int,int> , int> > q;
	    
	    // putting all the starting 1's into the queue
	    // with also marking them visited
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 1;
	                q.push({{i , j} , 0});
	            }
	        }
	    }
	    
	    // delrow and column for traversal in all four directions
	    
	    int delrow[] = {-1 , 0 , +1 , 0};
	    int delcol[] = {0 , +1 , 0 , -1};
	    
	    while(!q.empty()){
	        
	        // getting the information from the queue front
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        // assigning the distance
	        distance[row][col] = steps;
	        
	        // moving and checking in all four directions
	        for(int i=0 ; i<4 ; i++){
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            
	            if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < m 
	                && vis[nrow][ncol] == 0){
	                    vis[nrow][ncol] = 1;
	                    q.push({{nrow , ncol} , steps + 1});
	           }
	        }
	    }
	    
	    return distance;
	}
};