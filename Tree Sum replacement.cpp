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

void sumreplacement(Node* root){
	if(root==NULL)
		return;
	
	sumreplacement(root->left);
	sumreplacement(root->right);
	
	if(root->left != NULL){
		root->data += root->left->data;
	}
	
	if(root->right != NULL){
		root->data += root->right->data;
	}
}

void inorder(Node* root){
	if(root == NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<"Inorder               : ";
	inorder(root);
	cout<<"\nAfter Sum Replacement : ";
	sumreplacement(root);
	inorder(root);
	return 0;
}
