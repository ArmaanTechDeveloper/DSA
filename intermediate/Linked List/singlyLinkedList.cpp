#include <iostream>

using namespace std;

class Node{
    
    public:
        int data;
        Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    // destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory free for " << value << endl;
    }
    
};

void insertAtHead(Node* &head , int data){

    // new node creation
    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail , int data){

    // new node creation 
    Node* temp = new Node(data);

    tail-> next = temp;
    tail = temp;
}

void insertAtPosition(Node* & head , Node* &tail, int position , int data){

    if(position == 1){
        insertAtHead(head , data);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp  = temp -> next;
        cnt ++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail , data);
        return ;
    }

    // node creation
    Node* newNode = new Node(data);

    newNode -> next = temp -> next;
    temp -> next = newNode;
    

}

void deleteNode(Node* &head ,Node* & tail, int position ){

    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{

        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }

        if(curr->next == NULL){
            tail = prev;
        }
        prev->next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
    
}

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}
int main(){
    
    // craeting first node
    Node* node1 = new Node(10);
    // pointers
    Node* head = node1;
    Node* tail = node1;

    
    insertAtHead(head , 12);
    print (head);

    insertAtHead(head , 20);
    print (head);

    insertAtTail(tail , 30);
    print(head);

    insertAtPosition(head , tail , 4 , 5);
    print(head);

    deleteNode(head , tail , 1);
    print(head);
    cout << head -> data << " - " << tail -> data << endl;

    return 0;
}