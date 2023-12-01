#include <iostream>

using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    void solve(Node *root , int len , int& maxLen , int sum , int & maxSum){
        
        // base case
        if(root == NULL){
            
            if(len > maxLen){
                maxSum = sum;
                maxLen = len;
            }
            else if(len == maxLen){
                maxSum = max(sum , maxSum);
            }
            
            return;
        }
        
        
        sum += root -> data;
        solve(root -> left , len +1 , maxLen , sum , maxSum);
        solve(root -> right , len +1 , maxLen , sum , maxSum);
        
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0 , maxLen = 0 , sum = 0 , maxSum = INT_MIN;
        solve(root , len , maxLen , sum , maxSum);
        return maxSum;
    }
};