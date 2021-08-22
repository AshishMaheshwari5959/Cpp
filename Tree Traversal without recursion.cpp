#include<iostream>
#include<stack>
using namespace std;

class Node{
	public:
		Node* left;
		int data;
		Node* right;
		
		Node(int val){
			data = val;
			left = NULL;
			right = NULL;
		}
};

void inorder_without_recursion(Node* root){
	stack<Node *> s;
	Node* curr = root;
	
	while(curr != NULL || !s.empty() ){
		
		while(curr!=NULL){
			s.push(curr);
			curr = curr->left;
		}
		
		curr = s.top();
		s.pop();
		
		cout<<curr->data<<" ";
		
		curr = curr->right;
	}
}

void preorder_without_recursion(Node* root){
	stack<Node *> s;
	Node* curr = root;
	
	while(curr != NULL || !s.empty()){
		
		while(curr != NULL){
			s.push(curr);
			cout<<curr->data<<" ";
			curr = curr->left;
		}
		
		curr = s.top();
		s.pop();
		
		curr= curr->right;
	}
}

void postorder_without_recursion(Node* root){
	stack<Node *> s,o;
	Node* curr = root;
	s.push(curr);
	while(!s.empty()){
		curr = s.top();
		s.pop();
		
		o.push(curr);
		
		if(curr->left != NULL){
			s.push(curr->left);
		}
		if(curr->right != NULL){
			s.push(curr->right);
		}
	}
	
	while(!o.empty()){
		cout<<o.top()->data<<" ";
		o.pop();
	}
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<"\nInorder  -  ";
	inorder_without_recursion(root);
	cout<<"\nPreorder -  ";
	preorder_without_recursion(root);
	cout<<"\nPostorder - ";
	postorder_without_recursion(root);
	return 0;
}
