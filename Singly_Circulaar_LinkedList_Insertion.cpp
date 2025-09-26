#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;

// Insetion At head in singly circular linked list
void insertAtHead(int n){
    Node* newNode = new Node;
    newNode-> data =n;
    if ( head == NULL){
        head = newNode;
        newNode -> next = head;
    }
    else{
        Node* temp = head;
        while ( temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode ->next = head;
        head = newNode;
    }
}

// Insetion At end in singly circular linked list
void insertAtEnd(int n){
    Node* newNode = new Node;
    newNode-> data =n;
    if ( head == NULL){
        head = newNode;
        newNode -> next = head;
    }
    else{
        Node* temp = head;
        while ( temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode ->next = head;
    }
}

// Insetion At Specific position in singly circular linked list
void insertAtPosition(int pos, int n){
    Node* newNode = new Node;
    newNode -> data = n;
    if ( pos == 1 ){
        insertAtHead(n);
        return;
    }
    Node* temp = head;
    int count = 1;
    while( count < pos -1 && temp -> next != head){
        temp = temp -> next;
        count++;
    }
    if ( temp -> next == head && count < pos - 1){
        cout << "Invalid Position " << endl;
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
int main(){
    insertAtHead(5);
    // insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);
    insertAtEnd(6);
    insertAtPosition(4,8);
    return 0;
}
