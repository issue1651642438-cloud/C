# 这是数据结构与算法小班课的 **Class 5** 回顾

笔试 **6.23**

## 上机题目的模型题目

**树** 是重点、搜索、堆和贪心、KMP/字典树、

### 树

#### 二叉树的周游
 
preorder、midorder、levelorder（BFS）

不用递归，用栈周游（后续为例子）

树的深度

用周游重建二叉树（中序＋后序 重建二叉树）

文本树、拓展二叉树

    维护lastAtDepth[depth]

层序遍历：从侧面看，升空的烟火

### 二叉搜索树 BST

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

树形背包
- 回顾 **背包问题**

    bag capacity C0

    {stock} Vi, Pi
- 解法

    对于Xm，放还是不放？

    放了之后就是+Vm，价格+Pm

    当V相同时，比较 P1 与 P2

一般树转二叉树

## 搜索与状态图 DFS 与 BFS

连通块的个数：DFS

    创建dx[4]={1，-1，0，0},dy[4]={0，0，1，-1};
    循环遍历表格dfs（x+dx，y+dy）
    遇到没访问的空格 cnt++
    
最短步数：BFS用队列

多源的BFS：草坪起火

汉诺塔、八皇后

周期迷宫：无限远

## 堆、栈、**KMP**

Huffman编码 -- 堆

    #include<queue>
    using namespace std;

    priority_queue<>

从m个序列中各选应该数，求所有和中的最小的n个

    
Trie: 前缀关系

KMP

括号匹配——栈

波兰表达式——双栈：top的优先级大于cur，就运算


## 并查集

    int parent[MAX];

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i,int j){
        int root_i = find(i);
        int root_j = find(j);
        if(root_i!=root_j){
            parent[root_i] = root_j;
        }
    }

二分并查集

    引入parent[2*N]
    unite(x,y); unite(x+N,y+N);
    or
    unite(x,y+N); unite(x+N,y);

## DP——做不出来很正常

D++：给出伪代码，判断代码是否错误