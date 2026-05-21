#include<iostream>
#include<vector>
using namespace std;
#define MAX 10
vector<int> leftNum;
vector<int> rightNum;
int getDepth(int u){
    if(u==-1) return 0;
    if(leftNum[u]==-1&&rightNum[u]==-1){
        return 1;
    }else{
        int Ldep = getDepth(leftNum[u]);
        int Rdep = getDepth(rightNum[u]);
        return Ldep>=Rdep? Ldep+1:Rdep+1;
    }
}
int main(){
    int n;
    cin >> n;
    leftNum.push_back(0);
    rightNum.push_back(0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        leftNum.push_back(a);
        rightNum.push_back(b);
    }
    int deep = getDepth(1);
    cout<<deep<<endl;
}