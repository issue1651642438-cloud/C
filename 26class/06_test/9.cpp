#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode{
    char val;
    int deep;
    TreeNode *left,*right;
    TreeNode(char val,int deep): val(val), deep(deep), left(NULL), right(NULL){}
};

TreeNode* getTree(string str){
    int size = str.size();
    string leftstr,rightstr;
    stack <char> op;
    stack <TreeNode*> nodes;
    TreeNode* root=NULL,*cur=NULL;

    int k = 1;//标记左右孩子
    for(int i=0;i<size;i++){
        switch(str[i]){
            case '(':
                nodes.push(cur);
                k=1;
                break;
            case ',':
                k = 2;
                break;
            case ')':
                nodes.pop();
                break;
            default:
                cur = new TreeNode(str[i],nodes.size()+1);
                if(root == NULL){
                    root = cur;
                }else if (!nodes.empty()){
                    if(k==1) nodes.top()->left = cur;
                    else nodes.top()->right = cur;
                }
                break;
        }
    }
    return root;
}

int bfsAlg(TreeNode* tree, int k){
    int total = 0;
    queue <TreeNode*> bfs;
    bfs.push(tree);
    while(!bfs.empty()){
        TreeNode* cur = bfs.front();bfs.pop();
        if(cur->left!=NULL) bfs.push(cur->left);
        if(cur->right!=NULL) bfs.push(cur->right);

        if(cur->deep==k) total++;
        else if(cur->deep>k) return total;
    }
    return total;
}

int main(){
    string str;
    int k=0;
    cin>>str>>k;
    TreeNode* tree = getTree(str);
    int number = bfsAlg(tree,k);
    cout<<number<<endl;
    return 0;
}