

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map <int , int> m;
        
        vector <int> ans;
        // int in queue is for horizontal distance
        queue <pair <Node* , int> > q;
        
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            
            pair <Node* , int> front = q.front();
            q.pop();
            
            Node * frontNode = front.first;
            int hd = front.second;
            
                // updating mapping everytime
                m[hd] = frontNode -> data;

            
            if(frontNode -> left){
                q.push(make_pair(frontNode -> left , hd -1));
            }
            if(frontNode -> right){
                q.push(make_pair(frontNode -> right , hd +1));
            }
        }
        
        // for(auto i : m){
        //     ans.push_back(i.second);
        // }
        
        
        return ans;
    }
};