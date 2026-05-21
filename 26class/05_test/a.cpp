#include<iostream>
#include<vector>
using namespace std;
struct Node {
    struct Node *left,*right;
    int weight;

    Node(int w){
        weight = w;
        left = NULL;
        right = NULL;
    }
};

void selectMin(vector<Node*>& nodes,int& s1,int& s2){
    s1 = -1;
    s2 = -1;
    for(int i=0;i<nodes.size();i++){
        if(s1 ==-1||nodes[i]->weight < nodes[s1]->weight){
            s2 = s1;
            s1 = i;
        }else if(s2 == -1 || nodes[i]->weight < nodes[s2]->weight){
            s2 = i;
        }

        
    }
    if (s1>s2){
        int temp = s2;
        s2 = s1;
        s1 = temp;
    }
}

int getWPL(Node* root, int depth){
    if(root == NULL) return 0;

    if(root->left == NULL&&root->right == NULL){
        return root->weight*depth;
    }
    return getWPL(root->left,depth+1)+getWPL(root->right,depth+1);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<Node*>nodes;
        for(int i=0;i<n;i++){
            int w;
            cin>>w;
            nodes.push_back(new Node(w));
        }

        while(nodes.size()>1){
            int s1,s2;
            selectMin(nodes,s1,s2);
            Node* parent = new Node(nodes[s1]->weight+nodes[s2]->weight);
            parent->left = nodes[s1];
            parent->right = nodes[s2];

            nodes.erase(nodes.begin()+s2);
            nodes.erase(nodes.begin()+s1);
            nodes.push_back(parent);
        }

        Node* root = nodes[0];
        cout<<getWPL(root,0)<<endl;
    }
}