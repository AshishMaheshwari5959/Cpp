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

void insertAtHead(Node* &head, int val){
	Node* n = new Node(val);
	Node* temp = head;
	
	while(temp->next != head){
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
	head = n;
	return;
}

void insertAtTail(Node* &head, int val){
	Node* n = new Node(val);
	Node* temp = head;
	
	if(temp == NULL){
		head = n;
		head->next = head;
		return;
	}
	
	while (temp->next != head){
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
	return;
}

void deletion(Node* &head, int pos){
	int counter = 1;
	Node* temp = head;
	Node* prevptr = NULL;
	
	while(temp->next != head){
		prevptr = temp;
		temp=temp->next;
		counter++;
		if(counter==pos){
			prevptr->next = temp->next;
			break;
		}
	}
	if(pos==1){
		temp->next = head->next;
		head = head->next;
	}
	return;
}

void display(Node* head){
	Node* temp = head;
	while(temp->next != head){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	return;
}

int main(){
	Node* head = NULL;
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtTail(head,5);
	insertAtTail(head,6);
	insertAtTail(head,7);
	insertAtTail(head,8);
	display(head);
	deletion(head,1);
	display(head);
	return 0;
}
