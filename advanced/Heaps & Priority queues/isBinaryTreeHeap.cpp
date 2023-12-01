// Structure of node

#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int countNodes(struct Node * root){
        if(root == NULL){
            return 0;
        }
        
        return (1 + countNodes(root -> left) + countNodes(root -> right));
    }
    bool isCBT(struct Node * root , int i , int totalNodes){
        if(root == NULL){
            return true;
        }
        else if(i >= totalNodes){
            return false;
        }
        else{
            bool left = isCBT(root -> left , 2 * i + 1 , totalNodes);
            bool right = isCBT(root -> right , 2 * i + 2 , totalNodes);
            return left && right;
        }
    }
    
    bool isMaxOrder(struct Node * root){
        if(root->left == NULL && root -> right == NULL){
            return true;
        }
        else if(root -> left != NULL && root -> right == NULL){
            return (root -> data > root -> left -> data);
        }
        else{
            return (isMaxOrder(root ->left) && isMaxOrder(root -> right)) &&
                    (root -> data > root -> left -> data && root -> data > root->right -> data);
        }
    }
    bool isHeap(struct Node* tree) {
        
        int index = 0;
        int totalNodes = countNodes(tree);
        if(isCBT(tree , index , totalNodes) && isMaxOrder(tree)){
            return true;
        }
        return false;
    }
};