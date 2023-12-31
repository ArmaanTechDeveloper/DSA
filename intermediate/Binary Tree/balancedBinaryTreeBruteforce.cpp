#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    
    private: 
    
    int height(Node * root){
        if(root == NULL){
            return 0;
        }
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        return max(left , right) +1;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL){
            return true;
        }
        
        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        
        bool thirdCondition = abs(height(root -> left) - height(root -> right))  <= 1;
        
        if(left && right && thirdCondition){
            return true;
        }
        
        return false;
    }
};