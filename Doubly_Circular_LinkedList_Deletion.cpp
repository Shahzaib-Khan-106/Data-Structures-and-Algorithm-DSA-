#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;
void insert(int n){
    Node* newNode = new Node;
    newNode-> data =n;
    if (head == NULL){
        head = newNode;
        newNode -> next = head;
        newNode -> prev = head;
    }
    else{
        Node* last = head-> prev;
        newNode -> next = head;
        newNode -> prev = last;
        last->next = newNode;
        head -> prev = newNode;
        head = newNode;
    }
}
// Function to insert elements at Beginning in Doubly Circular Linked List
void insertAtBeginning(int n){
    Node* newNode = new Node;
    newNode-> data =n;
    if (head == NULL){
        head = newNode;
        newNode -> next = head;
        newNode -> prev = head;
    }
    else{
        Node* last = head-> prev;
        newNode -> next = head;
        newNode -> prev = last;
        last->next = newNode;
        head -> prev = newNode;
        head = newNode;
    }
}

// Function to insert elements at End in Doubly Circular Linked List
void insertAtEnd(int n){
    Node* newNode = new Node;
    newNode -> data = n;
    if ( head == NULL){
        newNode -> next = newNode;
        newNode -> prev = newNode;
        head = newNode;
    }
    else {
         Node* last = head-> prev;
        newNode -> next = head;
        newNode -> prev = last;
        last->next = newNode;
        head -> prev = newNode;
    }
}

// Function to insert elements at specific position in Doubly Circular Linked List
void insertAtposition(int pos, int n){
        Node* newNode = new Node;
    newNode -> data = n;
    if (pos == 1){
        insertAtBeginning(n);
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
    Node* nextNode = temp->next;
    newNode -> next = nextNode;
    newNode -> prev = temp;
    temp -> next = newNode;
    nextNode -> prev = newNode;
}

// Function to Delete elements at beginning in Doubly Circular Linked List
void deleteAtbeginning(){
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
        Node* Last = head->prev;
        head = head -> next;
        Last -> next = head;
        head -> prev = Last;
        delete temp;
    }
}

// Function to Delete elements at End in Doubly Circular Linked List
void deleteAtEnd(){
    if (head == NULL){
        cout << "The linked List is empty. Nothing to Delete." << endl;
        return;
    }
    if (head-> next == head){
        delete head;
        head = NULL;
    }
    else{
        Node* temp = head-> prev;
        Node* secondLast = temp-> prev;
        secondLast-> next = head;
        head->prev = secondLast;
        delete temp;
    }
}

// Function to Delete elements at specific position in Doubly Circular Linked List
void deleteAtPosition(int pos){
    if (head == NULL){
        cout << "The linked List is empty. Nothing to Delete." << endl;
        return;
    }
    if ( pos == 1){
        deleteAtbeginning();
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count < pos && temp->next != head){
        temp = temp-> next;
        count++;
    }
    if ( count != pos){
        cout << "Invalid Position" << endl;
        return;
    }
    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    if(temp== head){
        head=nextNode;
    }
    delete temp;
}
// Function to print elements in Doubly Circular Linked List
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
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insertAtBeginning(0);
    insertAtBeginning(-1);
    insertAtEnd(6);
    insertAtposition(3,10);
    insertAtposition(20,10);
    // deleteAtbeginning();
    // deleteAtEnd();
    deleteAtPosition(3);
    deleteAtPosition(3);
    print();
}
