#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int s, int e, int ele){
    for(int i=s; i<=e; i++){
        if(inorder[i]==ele){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int index = 4;

    if(start>end){
        return NULL;
    }

    int curr = postorder[index];
    Node* node = new Node(curr);
    index--;

    if(start==end){
        return node;
    }

    int pos = search(inorder,start,end,curr);
    node->right = buildTree(postorder,inorder,pos+1,end);
    node->left = buildTree(postorder,inorder,start,pos-1);

    return node;
}

void inorderPrint(struct Node* root){
    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int postorder[] = {4,2,5,3,1};

    Node* root = buildTree(postorder,inorder,0,4);

    cout<<"Inorder : ";
    inorderPrint(root);

    return 0;
}
