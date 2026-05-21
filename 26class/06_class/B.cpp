#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Node{
public:
    char value;
    Node *left,*right;

    Node(char val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(char val, Node* root){
    if(root==nullptr){
        return new Node(val);
    }
    if(val>root->value){
        root->right = insert(val,root->right);
    }else if(val<root->value){
        root->left = insert(val,root->left);
    }
    return root;
}

void preprint(Node* root){
    if(root==nullptr) return;
    cout<<root->value;
    preprint(root->left);
    preprint(root->right);
    return;
}

int main(){
    stack<string> strs;
    string str;
    while(1){
        getline(cin,str);
        if(!(str=="*"||str=="$")){
            strs.push(str);
            continue;
        }
        Node* root = nullptr;
        while(!strs.empty()){
            string s = strs.top();
            strs.pop();
            for(int i=0;s[i]!='\0';i++){
                root = insert(s[i],root);
            }
        }
        preprint(root);
        cout<<endl;
        if(str=="$") return 0;
    }
}