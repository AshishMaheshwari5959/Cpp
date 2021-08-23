#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
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

void leftview(Node* root){
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	cout<<q.front()->data<<" ";
	while (!q.empty()){
		Node* curr = q.front();
		q.pop();
		if(curr != NULL){
			if(curr->left != NULL){
				q.push(curr->left);
			}
			if(curr->right != NULL){
				q.push(curr->right);
			}
		} else {
			if(!q.empty()){
				cout<<q.front()->data<<" ";
				q.push(NULL);
			}
		}
	}
}

void rightview(Node* root){
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	cout<<q.front()->data<<" ";
	while (!q.empty()){
		Node* curr = q.front();
		q.pop();
		if(curr != NULL){
			if(curr->right != NULL){
				q.push(curr->right);
			}
			if(curr->left != NULL){
				q.push(curr->left);
			}
		} else {
			if(!q.empty()){
				cout<<q.front()->data<<" ";
				q.push(NULL);
			}
		}
	}
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	root->right->right->right = new Node(6);
	root->right->right->right->left = new Node(7);
	root->right->right->right->right = new Node(8);
	root->right->right->right->left->left = new Node(9);
	root->right->right->right->left->right = new Node(10);
	cout<<"Left View  : ";
	leftview(root);
	cout<<"\nRight View : ";
	rightview(root);
	return 0;
}
