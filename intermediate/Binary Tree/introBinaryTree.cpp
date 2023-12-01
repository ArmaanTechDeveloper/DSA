// Implement a Binary tree and do BFS(Level order traversal) and DFS(inorder , preorder , post order traversal) in the tree

#include <iostream>
#include <queue>

using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
Node * buildTree(Node * root){

    // taking input for the root node
    cout << "Enter data : "<<endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    // build the left side of the tree
    cout << "Enter data for inserting in the left of " << data << endl;
    root -> left = buildTree(root -> left);

    // build the right side of the tree
    cout << "Enter data for inserting in the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;

}


// BFS - Breadth first Search - Level order Traversal

void levelOrderTraversal(Node * root){

    string level = "";
    if(root == NULL)
        return ;
    
    queue <Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i=0 ; i < size ; i ++){
            Node * temp = q.front();
            q.pop();
            level += to_string(temp -> data) + " ";

            if(temp -> left != NULL)
                q.push(temp -> left);
            
            if(temp -> right != NULL)
                q.push(temp -> right);
        }

        cout << level << endl;
        level = "";
    }

}


void inOrderTraversal(Node * root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(Node * root){

    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);

}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}
int main(){
    

    Node * root = NULL;
    root = buildTree(root);

    cout << endl << endl;
    cout << "Breadth First Search(BFS) of the Binary Tree is " << endl;
    levelOrderTraversal(root);
    cout << endl << endl;
    cout << "All below are Depth First Search(DFS) of the Binary Tree " << endl;
    cout << "In order Traversal of the Binary Tree is " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre Order Traversal of the Binary Tree is " << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal of the Binary Tree is " << endl;
    postOrderTraversal(root);
    cout << endl;


    return 0;
}