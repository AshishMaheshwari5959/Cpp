#include<iostream>
#include<queue>
#include<vector>
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

static vector<int> v;

void levelorder(struct Node* root){
    if(root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int sum = 0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node != NULL){
            sum += node->data;
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        } else {
            if(!q.empty()){
                q.push(NULL);
                v.push_back(sum);
                sum = 0;
            }
        }
    }
    v.push_back(sum);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Level order : ";
    levelorder(root);
    cout<<endl<<"Sum at each level : ";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
