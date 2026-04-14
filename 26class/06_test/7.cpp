#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
struct Node{
    char val;
    Node* left,*right,*parent;
    
    Node(char c) : val(c), left(nullptr), right(nullptr), parent(nullptr) {}
};
vector<Node*> nodes;

string GetPost(Node* root){
    string post;
    if(root->val=='.') return "";

    post = GetPost(root->left)+GetPost(root->right)+root->val;
    return post;
}
string GetIn(Node* root){
    string in;
    if(root->val=='.') return "";

    in = GetIn(root->left)+root->val+GetIn(root->right);
    return in;
}

int main(){
    string line;
    getline(cin,line);
    for(int i=0;i<line.size();i++){
        char name = line[i];
        Node* node = new Node(name);
        nodes.push_back(node);

        if(nodes.size()!=1){
            for(int j = nodes.size()-2;j>=0;j--){
                if(nodes[j]->val!='.'&&nodes[j]->left==nullptr){
                    nodes[j]->left = node;
                    node->parent = nodes[j];
                    break;
                }else if(nodes[j]->val!='.'&&nodes[j]->right==nullptr){
                    nodes[j]->right = node;
                    node->parent = nodes[j];
                    break;
                }
            }
        }
    }
    string in = GetIn(nodes[0]);
    cout<<in<<endl;
    string post = GetPost(nodes[0]);
    cout<<post<<endl;

}