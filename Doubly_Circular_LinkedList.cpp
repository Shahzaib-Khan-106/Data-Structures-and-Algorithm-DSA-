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
    newNode-> next = NULL;
    newNode-> prev = NULL;
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
int main(){
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
}