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

void intersect(Node* &h1, Node* &h2, int pos){
	Node* temp1 = h1;
	Node* temp2 = h2;
	int counter = 1;
	
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	while(temp1!=NULL && counter<pos-1){
		temp1 = temp1->next;
		counter++;
	}
	temp2->next = temp1->next;
	return;
}

int length(Node* head){
	Node* temp= head;
	int l=0;
	
	while(temp!=NULL){
		temp=temp->next;
		l++;
	}
	return l;
}

int detectIntersection(Node* h1,Node* h2){
	int l1 = length(h1);
	int l2 = length(h2);
	int k = l1>l2?(l1-l2):(l2-l1);
	int counter = 1;
	Node* temp1 = h1;
	Node* temp2 = h2;
	
	if(l1>l2){
		while(temp1!=NULL && counter<=k){
			temp1=temp1->next;
			counter++;
		}
	} else {
		while(temp2!=NULL && counter<=k){
			temp2=temp2->next;
			counter++;
		}
	}
	
	while(temp1->next != NULL && temp2->next != NULL && temp1 != temp2){
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	
	if(temp1==temp2){
		return temp1->data;
	} else {
		return -1;
	}
}

int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;
	insertAtTail(head1,1);
	insertAtTail(head1,2);
	insertAtTail(head1,3);
	insertAtTail(head1,4);
	insertAtTail(head1,5);
	insertAtTail(head1,6);
	insertAtTail(head1,7);
	insertAtTail(head2,8);
	insertAtTail(head2,9);
	intersect(head1,head2,4);
	display(head1);
	display(head2);
	int x = detectIntersection(head1,head2); 
	if(x != -1){
		cout<<"Intersection at "<<x;
	} else {
		cout<<"No Intersection";
	}
	return 0;
}
