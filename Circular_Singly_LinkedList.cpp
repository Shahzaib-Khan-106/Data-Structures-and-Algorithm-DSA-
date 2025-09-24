#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;
void insert(int n){
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
int main(){
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
}
