#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);

    if(head==NULL){
        head=n;
        return;
    }

    Node* temp = head;
    head = n;
    n->next = temp;
    return;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

bool search(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletion(Node* head, int key){
    Node* temp = head;
    Node* p;
    while(temp!=NULL){
        if(temp->data == key){
            p->next = temp->next;
            break;
        }
        p = temp;
        temp = temp->next;
    }
    if(temp==NULL){
        cout<<"\nElement is not present cannot Delete\n";
        return;
    }
}

Node* reverse(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

Node* reverseRecursion(Node* &head){
    if((head==NULL) || (head->next==NULL)){
        return head;
    }
    Node* newhead = reverseRecursion(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;

    return newhead;
}
int main(){
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);
    return 0;
}
