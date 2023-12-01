#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class Solution {
private:
    int findposition(int element , int in[] , int start , int end)
    {
        for(int i = start ; i <= end ; i++)
        {
            if(in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    
    Node* constructTree(int pre[], int in[],
                        int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        int element = pre[preStart];
        Node* root = new Node(element);
        int position = findposition(element , in , inStart , inEnd);
        int numsLeft = position - inStart;

        root->left = constructTree(pre, in, preStart + 1, preStart + numsLeft, inStart, position - 1);
        root->right = constructTree(pre, in, preStart + numsLeft + 1, preEnd, position + 1, inEnd);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        return constructTree(pre, in, 0, n - 1, 0, n - 1);
    }
};