#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val){
        prev = NULL;
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    Node* temp = head;

    if(temp==NULL){
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
    return;
}

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    Node* temp = head;

    if(temp==NULL){
        head = n;
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return;
}

void deletion(Node* &head, int pos){
    Node* temp = head;
    int counter = 1;

    while(temp!=NULL){
        if(counter==pos){
            break;
        }
        temp = temp->next;
        counter++;
    }
    if(temp==NULL){
        cout<<"Entered Position Exceeded\n";
        return;
    }
    Node* prevptr = temp->prev;
    Node* nextptr = temp->next;
    if(prevptr != NULL){
        prevptr->next = nextptr;
    } else {
        head = nextptr;
    }
    if(nextptr != NULL){
        nextptr->prev = prevptr;
    }
    return;
}

void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    Node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,1);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    deletion(head,8);
    display(head);
    return 0;
}
