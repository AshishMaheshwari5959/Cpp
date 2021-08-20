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

void insertAtTail(Node* &head,int val){
	Node* n = new Node(val);
	Node* temp = head;
	
	if(temp==NULL){
		head = n;
		return;
	}
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	return; 
}

void display(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp= temp->next;
	}
	cout<<"NULL\n";
	return;
}

Node* merge(Node* h1, Node* h2){
	Node* newhead = NULL;
	Node* temp1 = h1;
	Node* temp2 = h2;
	Node* temp3 = newhead;
	
	while(temp1!=NULL && temp2!=NULL){
		if(temp1->data < temp2->data){
			if(newhead==NULL){
				newhead = temp1;
				temp3 = newhead;
			} else {
				temp3->next = temp1;
				temp3 = temp3->next;
			}
			temp1= temp1->next;
		} else {
			if(newhead==NULL){
				newhead = temp2;
				temp3 = newhead;
			} else {
				temp3->next = temp2;
				temp3 = temp3->next;
			}
			temp2= temp2->next;
		}
	}
	
	while(temp1!= NULL){
		if(newhead==NULL){
			newhead = temp1;
			temp3 = newhead;
		} else {
			temp3->next = temp1;
			temp3 = temp3->next;
		}
		temp1 = temp1->next; 
	}
	
	while(temp2!= NULL){
		if(newhead==NULL){
			newhead = temp2;
			temp3 = newhead;
		} else {
			temp3->next = temp2;
			temp3 = temp3->next;
		}
		temp2 = temp2->next; 
	}
	
	return newhead;
}

int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;
	insertAtTail(head1,11);
	insertAtTail(head1,22);
	insertAtTail(head1,33);
	insertAtTail(head1,44);
	insertAtTail(head1,55);
	insertAtTail(head1,66);
	insertAtTail(head2,12);
	insertAtTail(head2,20);
	insertAtTail(head2,34);
	insertAtTail(head2,46);
	insertAtTail(head2,52);
	display(head1);
	display(head2);
	Node* newhead = merge(head1,head2);
	display(newhead);
	return 0;
}
