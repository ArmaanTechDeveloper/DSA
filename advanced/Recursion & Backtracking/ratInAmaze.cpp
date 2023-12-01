#include <bits/stdc++.h> 
#include <vector>

using namespace std;

bool isSafe(int newx ,int newy, int n,vector < vector < int >> & arr ,
             vector < vector <bool> >& visited ){

    if((newx >=0 && newx <n)&& (newy >=0 && newy < n) && (visited[newx][newy] == 0) &&
        (arr[newx][newy] == 1)
    ){
        return true;
    }
    return false;

}

void solve(int x , int y , vector < vector < int >> & arr , int n , 
            vector <string>& ans , vector < vector <bool> >& visited , string path){

    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    // D L R U
    if(isSafe(x+1, y, n, arr, visited)){

        solve(x+1, y, arr, n, ans, visited, path + 'D');

    }

    if(isSafe(x, y-1, n, arr, visited)){
        solve(x, y-1, arr, n, ans, visited, path + 'L');
    }
    if(isSafe(x, y+1, n, arr, visited)){
        solve(x, y+1, arr, n, ans, visited, path + 'R');
    }
    if(isSafe(x-1, y, n, arr, visited)){
        solve(x-1, y, arr, n, ans, visited, path + 'U');
    }
    visited[x][y] = 0;

    }
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector <string> ans;
    vector < vector <bool> > visited (n , vector <bool> (n,0));

    string path ="";
    if(arr[0][0] == 0){
        return ans;
    }
    solve(0,0,arr , n , ans , visited ,path);
    return ans;
}