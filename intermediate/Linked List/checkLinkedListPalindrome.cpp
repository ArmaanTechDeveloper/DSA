#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
    private:
    
    Node *findMiddle (Node * head){
        Node * fast = head -> next;
        Node * slow = head;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    Node * reverse(Node * temp){
        Node * curr = temp;
        Node * prev = nullptr;
        
        Node * next = nullptr;
        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        if(head -> next == NULL){
            return true;
        }
        
        Node * middle = findMiddle(head);
        Node * temp = middle -> next;
        middle -> next = reverse(temp);
        
        Node * first = head;
        Node * second = middle -> next;
        
        while(second != nullptr){
            if(first -> data != second -> data){
                return false;
            } 
            first = first -> next;
            second = second -> next;
        }
        
        
        temp = middle -> next;
        middle -> next = reverse(temp);
        return true;
        
    }
};
