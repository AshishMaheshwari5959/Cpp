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

vector<int> count_sum(Node* root){
	queue<Node*> q;
	Node* curr = root;
	q.push(curr);
	q.push(NULL);
	int sum=0, count=0;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		
		if(curr != NULL){
			sum = sum + curr->data;
			count++;
			if(curr->left != NULL){
				q.push(curr->left);
			}
			if(curr->right != NULL){
				q.push(curr->right);
			}
		} else {
			if(!q.empty())
				q.push(NULL);
		}
	}
	vector<int> r;
	r.push_back(sum);
	r.push_back(count);
	return r;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	vector<int> r = count_sum(root);
	cout<<"Total Nodes  : "<<r[1];
	cout<<"\nSum of Nodes : "<<r[0];
	return 0;
}
