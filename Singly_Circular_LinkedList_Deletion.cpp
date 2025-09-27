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

// Function to Delete elements at Beginning in Singly Circular Linked List
void deleteAtBeginning(){
    if (head == NULL){
        cout << "The linked List is empty. Nothing to Delete." << endl;
        return;
    }
    if (head-> next == head){
        delete head;
        head = NULL;
    }
    else{
        Node* temp = head;
        Node* Last = head;
        while(Last-> next  != head){
            Last = Last -> next;
        }
        head = head -> next;
        Last -> next = head;
        delete temp;
    }
}


// Function to Delete elements at END in Singly Circular Linked List
void deleteAtEND(){
     if (head == NULL){
        cout << "The linked List is empty. Nothing to Delete." << endl;
        return;
    }
    if (head-> next == head){
        delete head;
        head = NULL;
    }
    else{
        Node* temp = head;
        Node* prev = NULL;
        while( temp -> next!= head){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = head;
        delete temp;
    }
}

// Function to Delete elements at END in Singly Circular Linked List
void deleteAtPosition(int pos){
     if (head == NULL){
        cout << "The linked List is empty. Nothing to Delete." << endl;
        return;
    }
    if ( pos == 1){
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    int count = 1;
    while(count < pos && temp->next != head){
        prev = temp;
        temp = temp-> next;
        count++;
    }
    if ( temp -> next == head && count < pos){
        cout << "Invalid Position" << endl;
        return;
    }
    prev -> next = temp -> next;
    delete temp;
}
// Function to print elements in Singly  Circular Linked List
void print() {
    if ( head == NULL) {
        cout << "The list is empty. Nothing to Print" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
    while(temp!=head);
}
int main(){
    insertAtHead(5);
    // insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);
    insertAtEnd(6);
    insertAtPosition(4,8);
    // print();
    // deleteAtBeginning();
    // deleteAtEND();
    deleteAtPosition(3);
    print();
    return 0;
}
