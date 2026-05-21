#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

struct Node{
    char value;
    int childNum,fillChildNum;
    Node *fristKid, *nextBro;
    Node(char c, int n) : value(c), childNum(n), fillChildNum(0), fristKid(NULL), nextBro(NULL) {}
};
bool isFirst = true;
void overPrint(Node* root){
    if(root==NULL) return;
    overPrint(root->fristKid);
    if (!isFirst) {
        cout << " ";
    }
    cout<<root->value;
    isFirst = false;
    overPrint(root->nextBro);
}

int main(){
    int n;
    cin>>n;getchar();
    vector<Node*> roots;
    for(int i=0;i<n;i++){
        Node* cur;
        vector<Node*> nodes;

        string str;
        getline(cin,str);
        stringstream ss(str);
        char c;int num;
        while(ss>>c>>num){
            cur = new Node(c,num);
            nodes.push_back(cur);
        }

        int ptr = 0;
        for(int j=0;j<nodes.size();j++){
            cur = nodes[j];
            int childs = cur->childNum;
            for(int k = 0;k<childs;k++){
                ptr++;
                if(k==0){
                    cur->fristKid = nodes[ptr];
                }else{
                    nodes[ptr-1]->nextBro = nodes[ptr];
                }
            }
        }
        roots.push_back(nodes[0]);
    }
    for(int i=0;i<n;i++){

        overPrint(roots[i]);

    }
}