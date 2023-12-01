
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
    
public:
    void traverseLeft(Node * root , vector <int> & ans){
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        
        ans.push_back(root -> data);
        
        if(root -> left){
            traverseLeft(root -> left , ans);
        }
        else{
            traverseLeft(root -> right , ans);
        }
    }
    
    void traverseLeaf(Node * root , vector <int> & ans){
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
            return;
        }
        
        traverseLeaf(root -> left ,ans);
        traverseLeaf(root -> right , ans);
    }
    
    void traverseRight(Node * root , vector <int> & ans){
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        
        if(root -> right){
            traverseRight(root -> right , ans);
        }
        else{
            traverseRight(root -> left ,ans);
        }
        
        // coming back
        ans.push_back(root -> data);
    }

    vector <int> boundary(Node *root)
    {
        vector <int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root -> data);
        
        if(root -> left == NULL && root -> right == NULL){
            return ans;
        }
        
        // traversing left part
        traverseLeft(root -> left , ans);
        
        // traversing leaf nodes
        traverseLeaf(root , ans);
        
        // traversing right nodes
        traverseRight(root -> right , ans);
        
        return ans;
        
    }
};