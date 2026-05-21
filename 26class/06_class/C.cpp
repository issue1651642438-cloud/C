#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string value;
    int count;
    Node *left,*right;

    Node(string val){
        value = val;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(string val, Node* root){
    if(root==nullptr) return new Node(val);

    if(val==root->value){
        root->count++;
    }else if(val>root->value){
        root->right = insert(val,root->right);
    }else{
        root->left = insert(val,root->left);
    }
    return root;
}

void midprint(Node* root, int total){
    if(root==nullptr) return;

    midprint(root->left,total);
    cout<<root->value;
    printf(" %.4lf%\n",100.0*root->count/total);
    midprint(root->right,total);
    return;
}

int main(){
    int n;
    Node* root = nullptr;
    cin>>n;getchar();
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        root = insert(str,root);
    }
    midprint(root,n);
}