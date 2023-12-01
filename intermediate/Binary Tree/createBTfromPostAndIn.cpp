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

//Function to return a tree created from postorder and inoreder traversals.

int findPosition(int element , int in[] , int inStart , int inEnd){
    for(int i=inStart ; i <= inEnd ; i ++){
        if(in[i] == element){
            return i;
        }
    }
    
    return -1;
}

Node * constructTree(
    int post[] , int postStart , int postEnd ,
    int in[] , int inStart , int inEnd
){
    
    // base case
    if(postStart < postEnd || inStart > inEnd) return NULL;
    
    int element = post[postStart];
    Node * root = new Node (element);
    
    int inPosition = findPosition(element , in , inStart , inEnd);
    int elementsRight = inEnd - inPosition;
    
    // right call
    root -> right = constructTree(
        post , postStart - 1 , postStart - elementsRight,
        in , inPosition +1 , inEnd
    );
    
    // left call
    root -> left = constructTree(
        post , postStart - elementsRight - 1 , postEnd,
        in , inStart , inPosition -1
    );
    
    return root;
    
    
}

Node *buildTree(int in[], int post[], int n) {
    
    return constructTree(post , n-1 , 0 , in , 0 , n-1);
    
}