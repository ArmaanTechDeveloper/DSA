#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = nullptr;
        arb = nullptr;
    }
};



// } Driver Code Ends
class Solution
{
    
    private:
    
    void addNode(int data, Node* & head , Node *& tail){
        
        Node* newNode = new Node(data);
        
        if(tail == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        
    }
    public:
    Node *copyList(Node *head)
    {
        Node * copyHead = nullptr;
        Node * copyTail = nullptr;
        
        Node * temp = head;
        
        // copying the normal linked list
        while(temp != nullptr){
            addNode(temp -> data , copyHead , copyTail);
            temp = temp -> next;
        }
        
        temp = head;
        Node * copyTemp = copyHead;
        
        // creating link between
        unordered_map <Node * , Node* > mapping;
        
        while(temp != nullptr && copyTemp != nullptr){
            
            mapping[temp] = copyTemp;
            
            temp = temp -> next;
            copyTemp = copyTemp -> next;
        }
        
        // copying random pointers
        
        temp = head;
        copyTemp = copyHead;
        
        while(temp != nullptr){
            
            copyTemp -> arb = mapping[temp -> arb];
            
            temp = temp -> next;
            copyTemp = copyTemp -> next;
            
        }
        
        return copyHead;
    }

};