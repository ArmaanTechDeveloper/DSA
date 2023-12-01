
#include <iostream>
#include <vector>
#include <queue>

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


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// using level order traversal
    	
    	vector <int> ans;
    	queue <Node*> q;
    	
    	if(root == NULL){
    	    return ans;
    	}
    	
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()){
    	   
    	   int size = q.size();
    	   vector <int> result(size);
    	   
    	   
    	   for(int i=0 ; i < size ; i ++){
    	       Node * front = q.front();
    	       q.pop();
    	       
    	       int index = leftToRight? i : size-i-1;
    	       result[index] = front->data;
    	       
    	       if(front -> left){
    	           q.push(front -> left);
    	       }
    	       if(front -> right){
    	           q.push(front -> right);
    	       }
    	   }
    	   
    	   // change direction
    	   leftToRight = !leftToRight;
    	   
    	   for(auto i : result){
    	       ans.push_back(i);
    	   }
    	    
    	}
    	
    	return ans;
    }
};