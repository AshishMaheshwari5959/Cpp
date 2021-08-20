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
    Node* temp = head;

    if(temp==NULL){
        head=n;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}

int length(Node* head){
	int l=0;
	Node* temp = head;
	
	while(temp!=NULL){
		l++;
		temp = temp->next;
	} 
	
	return l;
}

void appendLast(Node* &head, int pos){
    Node* temp = head;
    Node* start = head;
    Node* prevptr = NULL;
    int counter=0,n = length(head);

    while(temp!=NULL){
        prevptr = temp;
        temp = temp->next;
        counter++;

        if(counter==n-pos){
            prevptr->next = NULL;
            head = temp;
        }
    }
    prevptr->next = start;
    return;
}

void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL\n";
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
    display(head);
	appendLast(head,2);
	display(head);
    return 0;
}
