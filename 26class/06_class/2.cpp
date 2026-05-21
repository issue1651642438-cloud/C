#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
struct Node{
    char val;
    Node *left,*right;
    Node() : left(NULL), right(NULL) {}
};

void getpre(Node* root){
    if(root==NULL) return;
    cout<<root->val;
    getpre(root->left);
    getpre(root->right);
}

void getafter(Node* root){
    if(root==NULL) return;
    getafter(root->left);
    getafter(root->right);
    cout<<root->val;
}

int main(){
    int n;cin>>n;
    vector<Node*> nodes(n+1);
    for(int i=1;i<=n;i++){
        nodes[i] = new Node();
    }
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        nodes[i]->val = c;

        int childNum = 0;
        int childL = 0;
        int childR = 0;
        while((cin>>childR)&&childR!=0){
            childNum++;
            if(childNum==1){
                nodes[i]->left = nodes[childR];
            }else{
                nodes[childL]->right = nodes[childR];
            }
            childL = childR;
        }
    }
    getpre(nodes[1]);cout<<endl;
    getafter(nodes[1]);cout<<endl;
}
