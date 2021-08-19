#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head,int val){
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

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* ptr;
    int counter=1;

    while(temp!=NULL && temp->next!=NULL){
        if(counter==pos){
            ptr=temp;
        }
        temp = temp->next;
        counter++;
    }
    temp->next = ptr;
    return;
}

bool detectCycle(Node* head){
    Node* slowptr = head;
    Node* fastptr = head;
    while(slowptr!=NULL && fastptr!=NULL && fastptr->next!=NULL){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
        if(slowptr==fastptr){
            return true;
        }
    }
    if(fastptr==slowptr){
        return true;
    } else {
        return false;
    }
}

void removeCycle(Node* &head){
    Node* slowptr = head;
    Node* fastptr = head;

    while(slowptr!=NULL && fastptr!=NULL && fastptr->next!=NULL){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if(slowptr==fastptr){
            break;
        }
    }

    fastptr = head;
    while(fastptr->next != slowptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next;
    }

    slowptr->next = NULL;
    return;
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
    insertAtTail(head,9);
    makeCycle(head,4);
    cout<<detectCycle(head)<<endl;
    if(!detectCycle(head))
        display(head);
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    if(!detectCycle(head))
        display(head);
    return 0;
}
