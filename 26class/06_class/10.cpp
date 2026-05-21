#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct Node{
    int value;
    int deep;
    Node *left,*right;
    Node(int val) : value(val), deep(1), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(root->value<val){
        root->left = insert(root->left,val);
    }else if(root->value>val){
        root->right = insert(root->right,val);
    }
    return root;
}

int main(){
    int n;cin>>n;
    Node* tree = NULL;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        tree = insert(tree,val);
    }
    
    if(tree==NULL){
        printf("0\n");
        return 0;
    }

    int max = -1;
    queue<Node*> nodes;
    nodes.push(tree);
    while(!nodes.empty()){
        Node* cur = nodes.front();nodes.pop();
        if(max<cur->deep) max = cur->deep;
        if(cur->left!=NULL){
            cur->left->deep = cur->deep+1;
            nodes.push(cur->left);
        }
        if(cur->right!=NULL){
            cur->right->deep = cur->deep+1;
            nodes.push(cur->right);
        }
    }

    printf("%d",max);
}