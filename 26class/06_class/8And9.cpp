#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int value;
    Node * left,*right;
    Node(int val) : value(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val<root->value){
        root->left = insert(root->left, val);
    }else if(val>root->value){
        root->right = insert(root->right, val);
    }
    return root;
}

int isFrist=1;
void frontPrint(Node* root){
    if(root==NULL) return;
    
    if(isFrist==0) printf(" ");
    printf("%d",root->value);
    isFrist = 0;

    frontPrint(root->left);
    frontPrint(root->right);
}


void levelPrint(Node* root){
    if(root==NULL) return;

    queue<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        Node* cur = nodes.front();nodes.pop();

        if(isFrist==0) printf(" ");
        printf("%d",cur->value);
        isFrist = 0;

        if(cur->left!=NULL){
            nodes.push(cur->left);
        }
        if(cur->right!=NULL){
            nodes.push(cur->right);
        }
    }
}

int main(){
    int value;
    Node* root = NULL;
    while(scanf("%d",&value)==1){
        root = insert(root,value);
    }
    // frontPrint(root);
    levelPrint(root);
    printf("\n");
    return 0;
}