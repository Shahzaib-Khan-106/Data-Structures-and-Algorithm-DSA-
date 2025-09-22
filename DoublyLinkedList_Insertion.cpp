#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;

};
Node *head=NULL;
void insert(int n){
    Node *newNode = new Node;
    newNode -> data =n;
    newNode -> next = head;
    newNode -> prev = NULL;
    if(head !=NULL){
        head ->prev = newNode;
    }
    head = newNode;
}

// Insertion At end of Doubly Linked List
void insertAtend(int n){
    Node *newNode = new Node;
    newNode -> data = n;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if (head == NULL){
        head = newNode;
    }
    else{
        Node *temp = head;
        while (temp -> next !=NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
    }
}

// Insertion at specifc position in Doubly Linked List
void insertAtPosition(int pos,int n){
    Node *newNode = new Node;
    newNode -> data = n;
    if (pos == 1){
        newNode -> next = head;
    newNode -> prev = NULL;
    if(head !=NULL){
        head ->prev = newNode;
    }
    head = newNode;
    return;
    }
    Node *temp = head;
    for ( int i = 1; i< pos -1 && temp !=NULL; i++){
        temp = temp -> next;
    }
    if ( temp == NULL){
        cout << "Position" << pos << "does not exist in the List."<< endl;
        return;
    }
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    if (temp -> next != NULL){
    temp -> next -> prev = newNode;
    }
    temp -> next = newNode;
}
void print(){
    cout << "Elements in Double Linked List are: ";
    Node *temp = head;
    while (temp !=NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main(){
    insert(5);
    // insert(4);
    insert(3);
    insert(2);
    insert(1);
    insertAtend(6);
    insertAtPosition(4,4);
    print();
    return 0;
}