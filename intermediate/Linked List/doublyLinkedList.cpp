#include <iostream>

using namespace std;

class Node{

    public:
        int data;
        Node* next;
        Node* prev;
    
    Node(int data){
        this-> data = data;
        this-> next = NULL;
        this-> prev = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for data " << val << endl;
    }
};

void insertAtHead(Node* &head , int data){

    Node* newNode = new Node(data);

    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &tail , int data){

    Node* newNode = new Node(data);

    newNode -> prev = tail;
    tail -> next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head , Node* &tail ,int position , int data){

    if(position == 1){
        insertAtHead(head , data);
        return;
    }
    else{
        int cnt = 1;

        Node* temp = head;
        while(cnt < position){
            temp = temp -> next;
            cnt ++;
        }
        if(temp -> next == NULL){
            insertAtTail(tail , data);
            return;
        }
        Node* newNode = new Node(data);
        newNode -> next = temp -> next;
        temp -> next -> prev = newNode;
        temp -> next = newNode;
        newNode -> prev = temp;
    }
}

void deleteNode(Node* &head , Node* &tail , int position){

    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;

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
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}
// use less functions
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len ++;
        temp = temp->next;
    }

    return len;
}

void print(Node* head , Node* tail){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "head tail " << head -> data << " - " << tail -> data << endl;

}
int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    cout << "The length of the list is " << getLength(head) << endl;

    insertAtHead(head , 5);

    insertAtHead(head , 13);

    insertAtHead(head , 8);

    insertAtTail(tail , 6);

    insertAtPosition(head , tail , 5 , 7);
    print(head , tail);

    deleteNode(head , tail , 3);
    print(head , tail);

    return 0;
}