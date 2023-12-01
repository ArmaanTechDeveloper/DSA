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
    
    pair <bool , int> isBalancedFast(Node * root){
        if(root == NULL){
            pair <bool , int> p = make_pair(true , 0);
            return p;
        }
        
        pair <bool , int> left = isBalancedFast(root -> left);
        pair <bool , int> right = isBalancedFast(root -> right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool thirdCondition = abs(left.second - right.second) <= 1;
        
        pair <bool , int> ans;
        ans.second = max(left.second , right.second) +1;
        
        if(leftAns && rightAns && thirdCondition){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};