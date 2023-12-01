#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    
    pair <bool , int> isSumTreeFast(Node * root){
        
        // base case
        if(root == NULL){
            pair <bool , int> p = make_pair(true , 0);
            return p;
        }
        
        // check for leaf node
        if(root -> left == NULL && root -> right == NULL){
            pair <bool , int> p = make_pair(true , root -> data);
            return p;
        }
        
        
        // left call
        pair <bool , int> left = isSumTreeFast(root -> left);
        pair <bool , int> right = isSumTreeFast(root -> right);
        
        bool isLeftSumTree = left.first;
        bool isRightSumTree = right.first;
        
        bool condition = root -> data == (left.second + right.second);
        
        pair <bool , int> ans;
        
        if(isLeftSumTree && isRightSumTree && condition){
            ans.first = true;
            ans.second = root -> data + left.second + right.second;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};