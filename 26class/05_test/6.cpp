#include<string.h>
#include<iostream>
#include <vector>
using namespace std;

struct Node {
    char val;
    int indexleft;
    Node *left, *right, *parent;
    int depth;  // 深度（-的数量）

    Node(char c, int d) : val(c), depth(d), left(nullptr), right(nullptr), parent(nullptr),indexleft(0) {}
};

vector<Node*> nodes;

void pre(Node* root) {
    if (!root) return;
    cout << root->val;
    pre(root->left);
    pre(root->right);
}
void post(Node* root) {
    if (!root) return;
    post(root->left);
    post(root->right);
    cout << root->val;
}
void in(Node* root) {
    if (!root) return;
    in(root->left);
    cout << root->val;
    in(root->right);
}

int main(){
    string s;
    while(getline(cin,s)){
        if(s=="0") break;

        int dep = s.size()-1;
        char c = s[dep];

        if(c=='*'){
            if(dep!=0){
                for(int i=nodes.size()-1;i>=0;i--){
                    if(nodes[i]->depth ==dep-1){
                        Node* fa = nodes[i];
                        if(fa->indexleft==0){
                            fa->indexleft = 1;
                            fa->left = nullptr;
                        }
                        break;
                    }
                }
            }
        }else{
            Node* u = new Node(c,dep);
            nodes.push_back(u);
            if(dep!=0){
                for(int i=nodes.size()-2;i>=0;i--){
                    if(nodes[i]->depth ==dep-1){
                        Node* fa = nodes[i];
                        if(fa->indexleft==0){
                            fa->left = u;
                            fa->indexleft = 1;
                        }
                        else fa->right = u;
                        u->parent = fa;
                        break;
                    }
                }
            }
        }

        
    }

    pre(nodes[0]);cout<<endl;
    post(nodes[0]);cout<<endl;
    in(nodes[0]);cout<<endl;
}