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
void print(){
    cout << "Elements in Double Linked List are: ";
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main(){
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    print();
    return 0;
}