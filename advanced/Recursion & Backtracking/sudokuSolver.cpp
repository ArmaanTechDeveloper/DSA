#include <bits/stdc++.h> 
#include <vector>

using namespace std;

bool isSafe(int row , int col , vector<vector<int>>& board , int val){
    for(int i=0 ; i < 9 ; i ++){
        // check for row
        if(board[row][i] == val)
            return false;
        // check for column
        if(board[i][col] == val)
            return false;
        // check for 3 * 3 matrix
        if(board[3* (row/3) + i/3][3* (col/3) + i%3] == val)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>>& board){
    int n = board[0].size();

    for(int i = 0 ; i < n ; i ++){
        for (int j=0 ; j < n ; j ++){

            // check for empty space
            if(board[i][j] == 0){
                // solution try karo
                for(int sol=1 ; sol <= 9 ; sol ++){
                    // check for safety placement
                    if(isSafe(i, j , board , sol)){

                        // if safe then place
                        board[i][j] = sol;

                        // aage ka solution nikal ke lao
                        bool flag = solve(board);
                        if(flag){
                            return true;
                        }
                        else{
                            // back track
                            board[i][j] = 0;
                        }
                    }
                }

                // agar 1 - 9 tak koi bhi value nahi lagi
                // matlab solution exist nahi karta
                return false;
            }
        }
    }

    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}