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

class Solution {
  private: 
    int height(Node * root){
        if(root == nullptr){
            return 0;
        }
        
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        
        return (max(leftHeight , rightHeight) +1);
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == nullptr){
            return 0;
        }
        
        // 3 options 
        // left subtree mein hoga diameter
        // right subtree mein hoga diameter
        // dono mein mila ke hoga diameter
        int op1 = diameter(root -> left);
        int op2 = diameter(root -> right);
        int op3 = height(root -> left) + height(root -> right) + 1;
        
        int ans = max(op1 , max(op2 , op3));
        return ans;
    }
};