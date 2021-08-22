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

int height(Node* root){
	if(root == NULL){
		return 0;
	}
	
	int heightl = height(root->left);
	int heightr = height(root->right);
	return max(heightl,heightr)+1;
}

int diameter(Node* root){
	if(root==NULL){
		return 0;
	}
	int heightl = height(root->left);
	int heightr = height(root->right);
	int currdiameter = heightl+heightr+1;
	int diameterl = diameter(root->left);
	int diameterr = diameter(root->right);
	
	return max(currdiameter, max(diameterl, diameterr));
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<"Height of Tree  : "<<height(root)<<endl;
	cout<<"Diameter of Tree : "<<diameter(root);
	return 0;
}
