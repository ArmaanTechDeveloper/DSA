struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution
{
    private:
    
    Node * reverse(Node * head){
        Node * prev = nullptr;
        Node * curr = head;
        
        while(curr != nullptr){
            Node * next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void addNode(int digit , Node *& tail , Node *& head){

        Node* newNode = new Node(digit);
        if(tail == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    Node * add(Node * first , Node * second){
        
        Node * result = nullptr;
        Node * head = nullptr;
        int sum;
        int carry = 0;
        
        while(first != nullptr && second != nullptr){
            int val1 = first -> data;
            int val2 = second -> data;
            
            sum = val1 + val2 + carry;
            
            int digit = sum %10;
            addNode(digit , result , head);
            
            carry = sum / 10;
            
            first = first -> next;
            second = second -> next;
        }
        
        while(first != nullptr){
            sum = first -> data + carry;
            int digit = sum %10;
            addNode(digit , result, head);
            
            carry = sum / 10;
            
            first = first -> next;
        }
        
        while(second != nullptr){
            sum = second -> data + carry;
            int digit = sum %10;
            addNode(digit , result, head);
            
            carry = sum / 10;
            
            second = second -> next;
        }
        
        while(carry != 0){
            sum = carry;
            int digit = sum %10;
            addNode(digit , result, head);
            
            carry = sum / 10;
        }
        
        return head;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node * one = reverse(first);
        Node * two = reverse(second);
        
        Node * ans = add(one , two);
        ans = reverse(ans);
        return ans;
    }
};