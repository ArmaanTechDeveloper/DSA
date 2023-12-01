#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

// your task is to complete this function

Node * solve(Node * root , int& k , int node , int & ans){
    
    if(root == NULL){
        return NULL;
    }
    if(root -> data == node){
        return root;
    }
    // for left call
    Node * leftAns = solve(root -> left , k , node , ans);
    // for right call
    Node * rightAns = solve(root -> right , k , node , ans);
    
    
    if((leftAns != NULL && rightAns == NULL ) || (leftAns == NULL && rightAns != NULL)){
        
        k --;

        if(k == 0){
            // this is the ancestor
            k = INT_MAX;
            ans = root -> data;
        }
        
        if((leftAns != NULL && rightAns == NULL )){
            return leftAns;
        }
        else if((leftAns == NULL && rightAns != NULL)){
            return rightAns;
        }
        
    }
    else if (leftAns == NULL && rightAns == NULL){
        return NULL;
    }
    
}
int kthAncestor(Node *root, int k, int node)
{
    // ans should be root -> data
    int ans;
    if(root == NULL || root -> data == node){
        ans = -1;
    }
    else{
        solve(root , k , node , ans);
        if(k>=1 && k <= 100){
            ans = -1;
        }
    }
    
    return ans;
}